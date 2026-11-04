"""Promotion plans and announcement text only. Never modifies Discord or Sheets."""
import datetime as dt
import re

from attendance import UTC, eastern_offset, report

ANNOUNCEMENTS_CHANNEL = 1477486340625924209
CUSTOM_ASSETS_CHANNEL = 1483591827041812745
GUILD_ID = 1477486339984199932
CUSTOM_ASSETS_URL = f"https://discord.com/channels/{GUILD_ID}/{CUSTOM_ASSETS_CHANNEL}"
RANKS = (
    {"name": "Foundling", "prefix": "FD", "ops": 0, "role": 1477486340072276115, "reward": None},
    {"name": "Mandalorian Recruit", "prefix": "MR", "ops": 1, "role": 1477486340072276116, "reward": None},
    {"name": "Mandalorian Apprentice", "prefix": "MA", "ops": 5, "role": 1477486340072276117, "reward": "helmet"},
    {"name": "Mandalorian", "prefix": "MM", "ops": 10, "role": 1477486340072276118, "reward": "armor"},
    {"name": "Mandalorian Veteran", "prefix": "MV", "ops": 20, "role": 1477486340072276119, "reward": "backpack"},
)
PROTECTED_MEMBERS = {"248567812203872257"}  # User-confirmed Rally Master Edonn.
PROTECTED_PREFIXES = {"WC", "RM"}
PROTECTED_ROLE_IDS = {1477486340080799938, 1477486340080799946}


def is_protected(discord_id, nickname, role_ids, role_names=(), protected_role_ids=()):
    prefix = re.match(r"^\s*\[([^\]]+)\]\s*", nickname)
    return (str(discord_id) in PROTECTED_MEMBERS or bool(set(map(int, role_ids)).intersection(PROTECTED_ROLE_IDS | set(map(int, protected_role_ids))))
            or bool(prefix and prefix[1].upper() in PROTECTED_PREFIXES)
            or any(name.strip().casefold() in {"war chief", "rally master", "rallymaster"} for name in role_names))


def announcement(discord_id, rank):
    if not re.fullmatch(r"[0-9]{17,20}", str(discord_id)):
        raise ValueError("Invalid Discord member ID")
    if rank not in RANKS[1:]:
        raise ValueError("Announcements only support automatic progression promotions")
    text = f"Congratulations to <@{discord_id}> on promoting to {rank['name']}."
    if rank["reward"]:
        text += f" You can now submit a request for custom {rank['reward']} by creating a new post in [custom-assets]({CUSTOM_ASSETS_URL})."
    return text


def plan(db, discord_id, nickname, role_ids, role_names=(), protected_role_ids=(), now=None, credited_ops=None):
    discord_id = str(discord_id)
    now = now or dt.datetime.now(UTC)
    result = {"state": "review", "reason": "", "announcement_channel": ANNOUNCEMENTS_CHANNEL}
    prefix = re.match(r"^\s*\[([^\]]+)\]\s*", nickname)
    role_ids = set(map(int, role_ids))
    if is_protected(discord_id, nickname, role_ids, role_names, protected_role_ids):
        return {**result, "state": "protected", "reason": "Appointed rank/member: leave ALL roles and nickname untouched."}
    member = db.execute("SELECT steam_id,baseline_ops,tracking_since,active FROM members WHERE discord_id=?", (discord_id,)).fetchone()
    if not member or not member[3] or not member[2]:
        return {**result, "reason": "No active, dated roster link."}
    current = [index for index, rank in enumerate(RANKS) if rank["role"] in role_ids]
    if len(current) != 1:
        return {**result, "reason": "Exactly one managed progression role is required; staff must reconcile missing/conflicting roles."}
    if prefix and prefix[1].upper() not in {rank["prefix"] for rank in RANKS}:
        return {**result, "reason": "Unrecognized nickname prefix: do not overwrite it automatically."}
    if prefix and prefix[1].upper() != RANKS[current[0]]["prefix"]:
        return {**result, "reason": "Nickname prefix and progression role disagree; staff review required."}
    day = (now + dt.timedelta(hours=eastern_offset(now))).date()
    since = dt.date.fromisoformat(member[2])
    earned = 0
    warnings = []
    if credited_ops is not None:
        if not isinstance(credited_ops, int) or credited_ops < 0:
            raise ValueError("Finalized credit count must be a nonnegative integer")
        earned = credited_ops
    elif since <= day:
        data = report(db, since, day, now)
        warnings = data["warnings"]
        row = next(row for row in data["members"] if row["discord_id"] == discord_id)
        earned = row["earned_in_report_range"]
    total = member[1] + earned
    target = max(index for index, rank in enumerate(RANKS) if total >= rank["ops"])
    result.update(total_ops=total, baseline=member[1], new_ops=earned,
                  current=RANKS[current[0]]["name"], target=RANKS[target]["name"])
    if target <= current[0]:
        return {**result, "state": "unchanged", "reason": "No promotion due. Never demote for corrected attendance totals."}
    if warnings:
        return {**result, "reason": "Evidence warnings require review before promotion."}
    if member[1] >= RANKS[target]["ops"]:
        return {**result, "reason": "Eligible from historical baseline already: reconcile with staff; do not announce a historical promotion as new."}
    name = nickname[prefix.end():] if prefix else nickname
    proposed = f"[{RANKS[target]['prefix']}] {name}"
    if not name.strip() or len(proposed) > 32:
        return {**result, "reason": "Proposed nickname is empty or exceeds Discord's limit; do not truncate the character name."}
    return {**result, "state": "proposed", "reason": "Preview only; no role/nickname changes or announcement sent.",
            "add_role": RANKS[target]["role"], "remove_roles": [RANKS[current[0]]["role"]],
            "nickname": proposed, "announcement": announcement(discord_id, RANKS[target])}


def format_plan(result):
    lines = ["PROMOTION PREVIEW - " + result["state"], result["reason"]]
    if "total_ops" in result:
        lines += [f"Total evidence: {result['total_ops']} ({result['baseline']} starting + {result['new_ops']} new)",
                  f"Current: {result['current']}; eligible rank: {result['target']}"]
    if result["state"] == "proposed":
        lines += [f"Proposed nickname: {result['nickname']}",
                  "Only the five managed progression roles may change; all unrelated roles remain.",
                  f"Announcement destination: {result['announcement_channel']}", result["announcement"]]
    return "\n".join(lines)
