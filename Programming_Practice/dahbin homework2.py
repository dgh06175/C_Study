n = 0  # 누적합 변수 n에 0 초기화
m = 9  # 9의 배수변수 m에 9 초기화
i = 1
while True:  # 무한루프
    n += m * i
    if n <= 100:
        if i == 1:
            print(str(m * i), end='')
        else:
            print(" + " + str(m * i), end='')
    else:
        break
    i += 1
print(" = " + str(n - m * i))  # 마지막 반복에서는 n이 100이상이 되어서 else: break 된건데,
# 이때 n값은 100 이상이 될때도 9의 배수를 합해준 값이므로 에서 m * i 값을 빼줘야 올바른 누적합이다