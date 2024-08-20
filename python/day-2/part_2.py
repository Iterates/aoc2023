from typing import List
import re
from math import prod


def solve(lines: List[str]) -> None:
    matches = [re.findall(r'(?:\d{1,2}) (?:r|g|b)', line) for line in lines]
    total = 0
    for match in matches:
        sorted_match = {
            s.split()[1]: s.split()[0] for s in sorted(match, key=lambda e: int(e[:2]))
        }
        total += prod([int(value) for value in sorted_match.values()])
    print(total)
