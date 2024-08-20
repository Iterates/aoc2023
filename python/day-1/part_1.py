import re
from typing import List


def solve(lines: List[str]) -> None:
    total = sum(
        int(match[0]) * 10 + int(match[-1])
        for match in [re.findall(r"\d", line) for line in lines]
    )
    print(total)
