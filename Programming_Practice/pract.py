X = int(input('정수입력: '))
Y = int(input('정수입력: '))
n = 1
for m in range(Y):  # for문을 Y번 반복하면서, m에 첫번째 반복에는 0, 두번째에 1, 3번째에 2,... 마지막에는 Y를 대입함
    n = n * X
    if m < Y - 1: # 마지막 반복이 아닐때
        print(str(X) + ' * ', end='') # ex) X가 3이라면 '3 * '출력
    else:
        print(str(X) + ' = ', end='') # ex) X가 3이라면 '3 = '출력, end=''는 왜썼냐면 파이썬에선 print()함수를 쓰면 자동으로 \n이 마지막에 입력되는데, 이걸 없애줌
print(n)