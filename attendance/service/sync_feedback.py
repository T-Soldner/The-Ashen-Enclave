"""Actionable, non-secret sheet synchronization diagnostics."""


class SyncFailure(ValueError):
    def __init__(self, stage, error):
        self.stage = stage
        self.detail = str(error)[:500] if isinstance(error, ValueError) else 'External service or permissions error; inspect the server log.'
        super().__init__(f'{stage}: {self.detail}')


async def run_step(stage, callback):
    try:
        return await callback()
    except SyncFailure:
        raise
    except Exception as error:
        failure = SyncFailure(stage, error)
        print('Sheet sync failed: ' + str(failure), flush=True)
        raise failure from error


def instructions(error):
    stage = error.stage if isinstance(error, SyncFailure) else 'Sheet synchronization'
    detail = error.detail if isinstance(error, SyncFailure) else 'The result could not be verified.'
    lines = [f'{stage} was not confirmed.', f'Reason: {detail}']
    if stage in ('Clan grouping', 'Unit Roster'):
        lines.append('Attendance totals/history export already verified; the later display refresh failed.')
    lines += ['Run this read-only check first:', '`/tae-maintenance sheets preview`']
    if stage == 'Unit Roster':
        lines += ['Then preview the roster:', '`/tae-maintenance roster-sync`',
                  'Only after inspecting that fresh preview, run:', '`/tae-maintenance roster-sync confirm:True`']
    elif stage == 'Clan grouping':
        lines += ['Check Discord member access:', '`/tae-maintenance personnel-check`',
                  'If both checks pass, staff should inspect the hidden Attendance clan groups helper before retrying.']
    lines += ['If the preview reports uncertain receipts, stop and send the output to staff; do not keep retrying.',
              'For server diagnostics: `Get-Content D:\\TAEAttendance\\logs\\bot.log -Tail 30`',
              'Do not repeat rank corrections or operation finalization to repair a Sheet refresh.']
    return '\n'.join(lines)
