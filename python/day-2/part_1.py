from typing import List
import re


def solve(lines: List[str]) -> None:
    matches = [
        re.findall(
            r'(?:1[3-9]|[2-9]\d) r|(?:1[4-9]|[2-9]\d) g|(?:1[5-9]|[2-9]\d) b', line
        )
        for line in lines
    ]
    total = sum([i + 1 for i, match in enumerate(matches) if not bool(len(match))])

    print(total)
