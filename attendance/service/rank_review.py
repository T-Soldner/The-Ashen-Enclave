"""Read-only Discord rank/name audit against the finalized attendance ledger."""
import re
import promotions
import name_review


def correction(current, baseline, credited):
    if current['protected']:
        raise ValueError('Protected member: leave all roles and nickname untouched.')
    ranks = [rank for rank in promotions.RANKS if rank['role'] in current['roles']]
    if len(ranks) != 1:
        raise ValueError('Resolve missing/conflicting rank roles before approving a correction.')
    eligible = max((rank for rank in promotions.RANKS if baseline + credited >= rank['ops']), key=lambda rank: rank['ops'])
    if eligible['ops'] < ranks[0]['ops']:
        raise ValueError('Attendance suggests a lower rank. No automatic demotion; staff must review manually.')
    character = re.sub(r'^\s*\[[^\]]+\]\s*', '', current['nickname']).strip()
    return {'add_role': eligible['role'], 'remove_roles': [ranks[0]['role']] if ranks[0] != eligible else [],
            'nickname': name_review.nickname(eligible['prefix'], character),
            'expected_total': baseline + credited, 'target': eligible['name']}


def inspect(current, baseline, credited):
    if current['protected']:
        return 'PROTECTED - leave roles and nickname untouched.'
    ranks = [rank for rank in promotions.RANKS if rank['role'] in current['roles']]
    total = baseline + credited
    eligible = max((rank for rank in promotions.RANKS if total >= rank['ops']), key=lambda rank: rank['ops'])
    issues = []
    if len(ranks) != 1:
        issues.append('Missing/conflicting rank roles: ' + (', '.join(rank['name'] for rank in ranks) or 'none'))
    else:
        rank = ranks[0]
        prefix = re.match(r'^\s*\[([^\]]+)\]', current['nickname'])
        if not prefix or prefix[1].upper() != rank['prefix']:
            issues.append(f"Nickname prefix should be [{rank['prefix']}] for the current role")
        if eligible['ops'] > rank['ops']:
            issues.append(f"Attendance qualifies for {eligible['name']}; staff promotion review needed")
        elif eligible['ops'] < rank['ops']:
            issues.append('Current rank exceeds attendance threshold; do NOT automatically demote')
    return f"{total} ops; eligible: {eligible['name']}. " + ('; '.join(issues) if issues else 'OK')
