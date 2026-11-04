import ast
from pathlib import Path
from types import SimpleNamespace
import unittest

import clan_training as policy
from discord_bot import arrange_commands, command_help


class Group:
    def __init__(self, name, description="Description", **kwargs):
        self.name, self.description, self.commands = name, description, []
        self.parent = None

    def add_command(self, command):
        if command.parent is not None:
            raise ValueError("Detach command from its old parent before moving it")
        if len(self.commands) >= 25 or any(c.name == command.name for c in self.commands):
            raise ValueError("Duplicate command or Discord group limit exceeded")
        self.commands.append(command)
        command.parent = self

    def remove_command(self, name):
        command = next((c for c in self.commands if c.name == name), None)
        if command:
            self.commands.remove(command)
        # Exercise in-place removal without depending on its return value.
        return None

    def get_command(self, name):
        return next((c for c in self.commands if c.name == name), None)


def registered_commands():
    """Model actual decorator registrations, including the pre-move 25-child limit."""
    groups = {key: Group(key) for key in ("public", "staff", "training")}
    root = Path(__file__).parent
    for file in ("discord_bot.py", "application_ui.py", "personnel_ui.py"):
        tree = ast.parse((root/file).read_text(encoding="utf-8-sig"))
        for node in ast.walk(tree):
            if not isinstance(node, ast.Call) or not isinstance(node.func, ast.Attribute):
                continue
            if node.func.attr != "command" or not isinstance(node.func.value, ast.Name):
                continue
            group = groups.get(node.func.value.id)
            if group is None:
                continue
            name = next(k.value.value for k in node.keywords if k.arg == "name")
            group.add_command(Group(name))
    groups["public"].add_command(groups["training"])
    return groups


class HelpTests(unittest.TestCase):
    def setUp(self):
        groups = registered_commands()
        self.public, self.staff = groups["public"], groups["staff"]
        self.before = sum(len(g.commands) for g in groups.values()) - 1
        self.maintenance = arrange_commands(SimpleNamespace(Group=Group), self.public, self.staff)
        self.staff.add_command(Group("help"))

    def text(self, **kwargs):
        return "\n".join(command_help(self.public, self.staff, maintenance=self.maintenance, **kwargs))

    def test_exact_member_and_staff_surface(self):
        self.assertEqual({c.name for c in self.public.commands}, {"help", "status", "register", "clan-apply"})
        self.assertEqual({c.name for c in self.staff.commands}, {"help", "health", "member", "training", "transfer"})
        training = next(c for c in self.staff.commands if c.name == "training")
        self.assertEqual({c.name for c in training.commands}, {"edit", "status"})

    def test_all_recovery_handlers_retained_and_groups_under_limit(self):
        def leaves(group):
            self.assertLessEqual(len(group.commands), 25)
            return sum(leaves(c) if c.commands else 1 for c in group.commands)
        total = sum(leaves(g) for g in (self.public, self.staff, self.maintenance))
        self.assertEqual(total, self.before + 1)
        recovery = {c.name: c for c in self.maintenance.commands}
        self.assertEqual({c.name for c in recovery["links"].commands}, {"pending", "approve", "reject"})
        self.assertEqual({c.name for c in recovery["sheets"].commands}, {"bind", "preview", "init", "sync"})
        self.assertEqual({c.name for c in recovery["training"].commands}, {"legacy-import", "legacy-map", "legacy-auto-map"})

    def test_members_only_see_member_commands(self):
        text = self.text()
        self.assertIn("/tae register", text)
        self.assertNotIn("/tae-admin", text)
        self.assertNotIn("/tae-maintenance", text)

    def test_trainer_and_leader_sections(self):
        text = self.text(roles={policy.LEADER})
        self.assertIn("/tae-admin training edit", text)
        self.assertIn("/tae-maintenance clan-review", text)
        self.assertIn("/tae-maintenance roster-sync", text)
        self.assertNotIn("legacy-import", text)
        self.assertNotIn("/tae-admin transfer", text)
        self.assertNotIn("/tae-maintenance links approve", text)
        self.assertNotIn("clan-review", self.text(roles={policy.SECOND}))

    def test_recruiter_only_sees_authorized_staff_commands(self):
        text = self.text(roles={1477486340101902517})
        self.assertIn("/tae-maintenance application-review", text)
        self.assertNotIn("/tae-maintenance links approve", text)

    def test_admin_gets_advanced_commands_and_bounded_pages(self):
        pages = command_help(self.public, self.staff, administrator=True, maintenance=self.maintenance)
        self.assertTrue(all(len(page) <= 1900 for page in pages))
        self.assertIn("/tae-maintenance training legacy-import", "\n".join(pages))
        self.assertIn("/tae-maintenance links approve", "\n".join(pages))
        self.assertIn("/tae-maintenance sheets sync", "\n".join(pages))

    def test_moves_retain_same_command_objects(self):
        groups = registered_commands()
        approve = next(c for c in groups["staff"].commands if c.name == "approve")
        maintenance = arrange_commands(SimpleNamespace(Group=Group), groups["public"], groups["staff"])
        links = next(c for c in maintenance.commands if c.name == "links")
        self.assertIs(next(c for c in links.commands if c.name == "approve"), approve)
