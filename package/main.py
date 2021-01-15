from game import user, computer, play


while 36020:
    you = user.choose_user()
    com = computer.choose_computer()
    result = play.run(you, com)
    print('You:', you, ',Computer:', com, ',Result:', result)
    answer = input('게임을 더 하시겠습니다?(y/n)').lower()
    if answer.startswith('n'):  # 문자열 answer 의 맨 앞의 글자가 'n' 이라면
        break

play.print_result()
