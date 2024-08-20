import re
from typing import List


def solve(lines: List[str]) -> None:
    pattern = r'one|two|three|four|five|six|seven|eight|nine|1|2|3|4|5|6|7|8|9'
    digits = dict(zip(pattern.split('|'), [_ for _ in range(1, 10)] * 2))
    matches = [
        match for match in [re.findall(pattern, line) for line in lines] if match
    ]
    total = sum(digits[match[0]] * 10 + digits[match[-1]] for match in matches)
    print(total)
