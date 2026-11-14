"""Persistent, administrator-reviewed nickname corrections; no attendance edits."""
import json
import re

import promotions


def initialize(db):
    db.execute("""CREATE TABLE IF NOT EXISTS name_reviews (
        guild_id TEXT NOT NULL, operation TEXT NOT NULL, discord_id TEXT NOT NULL,
        state TEXT NOT NULL, payload TEXT NOT NULL, actor_id TEXT,
        PRIMARY KEY (guild_id,operation,discord_id))""")
    db.commit()


def proposal(current):
    if current['protected']:
        raise ValueError('Protected member: nickname and roles must remain untouched.')
    ranks = [rank for rank in promotions.RANKS if rank['role'] in current['roles']]
    if len(ranks) != 1:
        raise ValueError('Resolve missing/conflicting rank roles in Discord first.')
    name = re.sub(r'^\s*\[[^\]]+\]\s*', '', current['nickname']).strip()
    return nickname(ranks[0]['prefix'], name)


def nickname(prefix, name):
    name = name.strip()
    result = f'[{prefix}] {name}'
    if not name or len(result) > 32 or any(ord(c) < 32 for c in name) or '[' in name or ']' in name:
        raise ValueError('Use a name without rank brackets/control characters; full nickname must fit 32 characters.')
    return result


def save(db, guild, operation, who, state, payload, actor):
    with db:
        db.execute("""INSERT INTO name_reviews VALUES (?,?,?,?,?,?)
            ON CONFLICT(guild_id,operation,discord_id) DO UPDATE SET
            state=excluded.state,payload=excluded.payload,actor_id=excluded.actor_id""",
            (str(guild), operation, str(who), state, json.dumps(payload), str(actor)))


def panel_factory(discord, workflow):
    """One restart-safe panel per operation, with private per-person previews."""
    async def allowed(interaction):
        if not workflow.enabled or interaction.guild_id != int(workflow.guild_id) or not interaction.user.guild_permissions.administrator:
            await interaction.response.send_message('Discord administrators only.', ephemeral=True)
            return False
        return True

    class Decision(discord.ui.View):
        def __init__(self, operation, who, current, proposed, actor, role_plan=None):
            super().__init__(timeout=600)
            self.operation, self.who = operation, who
            self.current, self.proposed, self.actor = current, proposed, actor
            self.role_plan = role_plan

        async def interaction_check(self, interaction):
            return await allowed(interaction) and interaction.user.id == self.actor

        @discord.ui.button(label='Approve correction', style=discord.ButtonStyle.success)
        async def approve(self, interaction, button):
            await interaction.response.defer(ephemeral=True)
            async with workflow.lock:
                active = await workflow.db(lambda db: db.execute('SELECT active FROM members WHERE discord_id=?', (self.who,)).fetchone())
                if not active or not active[0]:
                    await interaction.followup.send('Member is no longer actively tracked. No changes made.', ephemeral=True)
                    return
                if self.role_plan:
                    from finalization import ledger_totals
                    totals = await workflow.db(lambda db: ledger_totals(db, workflow.guild_id))
                    total = next((baseline + credits for who, _, baseline, credits in totals if who == self.who), None)
                    if total != self.role_plan['expected_total']:
                        await interaction.followup.send('Attendance changed. Run a fresh review before approving.', ephemeral=True)
                        return
                    unresolved = await workflow.db(lambda db: db.execute(
                        "SELECT 1 FROM promotion_jobs WHERE guild_id=? AND discord_id=? AND state!='applied'",
                        (workflow.guild_id, self.who)).fetchone())
                    if unresolved:
                        await interaction.followup.send('An unresolved promotion exists. Inspect its receipt before applying another correction.', ephemeral=True)
                        return
                previous = await workflow.db(lambda db: db.execute(
                    'SELECT state FROM name_reviews WHERE guild_id=? AND operation=? AND discord_id=?',
                    (workflow.guild_id, self.operation, self.who)).fetchone())
                if previous and previous[0] in ('applying', 'uncertain'):
                    await interaction.followup.send('An earlier edit is uncertain. Inspect Discord and the receipt before retrying.', ephemeral=True)
                    return
                current = await workflow.transport.member(self.who)
                if current != self.current:
                    await interaction.followup.send('Member changed. Open a fresh review.', ephemeral=True)
                    return
                await workflow.db(lambda db: save(db, workflow.guild_id, self.operation, self.who,
                    'applying', {'before': current, 'nickname': self.proposed, 'role_plan': self.role_plan}, self.actor))
                try:
                    if self.role_plan:
                        await workflow.transport.apply(self.who, current, {**self.role_plan, 'nickname': self.proposed})
                    else:
                        await workflow.transport.rename(self.who, current, self.proposed)
                    def finish(db):
                        with db:
                            db.execute('UPDATE members SET display_name=? WHERE discord_id=? AND active=1', (self.proposed, self.who))
                            db.execute("UPDATE name_reviews SET state='approved' WHERE guild_id=? AND operation=? AND discord_id=?",
                                (workflow.guild_id, self.operation, self.who))
                    await workflow.db(finish)
                except Exception:
                    await workflow.db(lambda db: save(db, workflow.guild_id, self.operation, self.who,
                        'uncertain', {'before': current, 'nickname': self.proposed, 'role_plan': self.role_plan}, self.actor))
                    await interaction.followup.send('Could not verify the edit. Inspect Discord before retrying; no attendance totals changed.', ephemeral=True)
                    return
            sheet_status = ''
            if workflow.sheet_export is not None:
                try:
                    await workflow.sheet_export()
                    sheet_status = ' Sheet refresh verified.'
                except Exception:
                    sheet_status = ' Discord correction saved, but sheet refresh needs review; do not repeat the correction to retry Sheets.'
            await interaction.followup.send('Correction verified. ' + ('Attendance-based rank role and nickname updated; unrelated roles preserved. No historical promotion announcement sent. ' if self.role_plan else 'Nickname updated; roles unchanged. ') + 'Attendance totals unchanged. Existing recap messages are not rewritten.' + sheet_status, ephemeral=True)
            self.stop()

        @discord.ui.button(label='Deny change', style=discord.ButtonStyle.danger)
        async def deny(self, interaction, button):
            async with workflow.lock:
                state = await workflow.db(lambda db: db.execute(
                    'SELECT state FROM name_reviews WHERE guild_id=? AND operation=? AND discord_id=?',
                    (workflow.guild_id, self.operation, self.who)).fetchone())
                if state and state[0] in ('applying', 'uncertain'):
                    await interaction.response.send_message('Inspect the unresolved edit first; its receipt cannot be overwritten.', ephemeral=True)
                    return
                await workflow.db(lambda db: save(db, workflow.guild_id, self.operation, self.who,
                    'denied', {'nickname': self.proposed}, self.actor))
            await interaction.response.send_message('Change denied. No nickname, role or attendance changes.', ephemeral=True)
            self.stop()

        @discord.ui.button(label='Correct name', style=discord.ButtonStyle.secondary)
        async def correct(self, interaction, button):
            owner = self
            class Correction(discord.ui.Modal, title='Correct character name'):
                name = discord.ui.TextInput(label='Name only (no rank prefix)', max_length=32)

                async def on_submit(self, reply):
                    if not await allowed(reply) or reply.user.id != owner.actor:
                        return
                    try:
                        prefix = owner.proposed.split(']', 1)[0][1:]
                        proposed = nickname(prefix, str(self.name))
                    except ValueError as error:
                        await reply.response.send_message(str(error), ephemeral=True)
                        return
                    view = Decision(owner.operation, owner.who, owner.current, proposed, owner.actor, owner.role_plan)
                    await reply.response.send_message('Proposed nickname: ' + discord.utils.escape_markdown(proposed), view=view, ephemeral=True)
            await interaction.response.send_modal(Correction())

    class Select(discord.ui.UserSelect):
        def __init__(self, operation):
            super().__init__(placeholder='Select a person to review', min_values=1, max_values=1)
            self.operation = operation

        async def callback(self, interaction):
            if not await allowed(interaction):
                return
            await interaction.response.defer(ephemeral=True)
            who = str(self.values[0].id)
            eligible = await workflow.db(lambda db: db.execute(
                "SELECT 1 FROM operation_credits WHERE guild_id=? AND operation=? AND discord_id=? AND status='attended'",
                (workflow.guild_id, self.operation, who)).fetchone())
            if not eligible:
                await interaction.followup.send('Choose an attendee of this operation.', ephemeral=True)
                return
            current = await workflow.transport.member(who)
            try:
                from finalization import ledger_totals
                from rank_review import correction
                totals = await workflow.db(lambda db: ledger_totals(db, workflow.guild_id))
                total_row = next((row for row in totals if row[0] == who), None)
                if total_row is None:
                    raise ValueError('Member is no longer actively tracked.')
                plan = correction(current, total_row[2], total_row[3])
                proposed = plan['nickname']
            except ValueError as error:
                await interaction.followup.send(str(error), ephemeral=True)
                return
            text = (f"Current: {current['nickname']}\nSuggested: {proposed}\n"
                    f"Proposed rank: {plan['target']}, based on {plan['expected_total']} ops. "
                    'Use Correct name if the character name is wrong. Approve updates the rank role and nickname; '
                    'attendance totals and unrelated roles stay unchanged. No historical promotion announcement is sent.')
            await interaction.followup.send(discord.utils.escape_markdown(text),
                view=Decision(self.operation, who, current, proposed, interaction.user.id, plan), ephemeral=True)

    class Panel(discord.ui.View):
        def __init__(self):
            super().__init__(timeout=None)

        @discord.ui.button(label='Review ranks and names', custom_id='tae:operation-name-review:v1', style=discord.ButtonStyle.primary)
        async def review(self, interaction, button):
            if not await allowed(interaction):
                return
            row = await workflow.db(lambda db: db.execute(
                "SELECT post_key FROM workflow_posts WHERE guild_id=? AND kind='name-review' AND message_id=? AND state='sent'",
                (workflow.guild_id, str(interaction.message.id))).fetchone())
            if not row:
                await interaction.response.send_message('Review receipt unavailable; ask staff to inspect it.', ephemeral=True)
                return
            view = discord.ui.View(timeout=600)
            view.add_item(Select(row[0]))
            await interaction.response.send_message('Select an attendee. Review changes one person at a time; no bulk edits.', view=view, ephemeral=True)

    Panel.decision = Decision
    return Panel
