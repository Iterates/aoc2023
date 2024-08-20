def read(day: str):
    with open(f'./input/day-{day}.txt', encoding='utf-8') as file:
        output = file.read()
    return output.split('\n')
    