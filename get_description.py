def get_description():
    '''return random weather, just like the pros'''
    from random import choice
    possibilites = ['비', '눈', '안개', '해', '몰라']
    return choice(possibilites)


def prr():
    print('r')
possibilites = ['비', '눈', '안개', '해', '몰라']
a = 1
if __name__ == '__main__':  # 이 파일을 직접 실행시킬 때\ㅐ
    w = get_description()
    print(w)
