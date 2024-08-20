from sys import argv
from utils.read import read
from importlib import import_module


if __name__ == "__main__":
    day = argv[1]
    part = argv[2]
    module = import_module(f"day-{day}.part_{part}")
    lines = read(day)
    module.solve(lines)
