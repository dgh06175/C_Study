from collections import Counter

# count = {'win': 0, 'lose': 0, 'draw': 0}
count = Counter()


def run(p1, p2):
    if p1 == p2:
        result = 'draw'
    elif p1 == '가위':
        result = 'win' if p2 == '보' else 'lose'
    elif p1 == '바위':
        result = 'win' if p2 == '가위' else 'lose'
    else:
        result = 'win' if p2 == '바위' else 'lose'
    count[result] += 1
    return result


def print_result():
    print('Result'.center(40, '#'))
    print('Win:', count['win'], ',Lose:', count['lose'], ',Draw:', count['draw'])
    print('#'*40)


if __name__ == '__main__':
    print(run('가위', '보'))
    print(run('가위', '바위'))
    print(run('가위', '가위'))
    print(run('바위', '가위'))
    print(run('보', '가위'))
    print_result()
