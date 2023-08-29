n = 0  # 누적합 변수 n에 0 초기화
string = ""  # 마지막줄 출력할때 쓸 문자열 n에 빈 문자열 초기화
while True:
    m = int(input("정수입력 : "))
    n = n + m  # 누적합
    string = string + str(m) + " + "  # string 문자열에 이번에 m에 넣은 숫자랑 +를 "7 + " 이런식으로 붙혀줌
    if m == 0:  # 0 입력시 종료
        break
print(string[:-3] + " = " + str(
    n))  # stirng[:3]한 이유: 그냥 string이라고 쓰면 맨 뒤에 "  +"문자가 남아있어서 1 + 2 + 3 + 0 +  = 6 이런식으로 이상하게 출력되므로 string문자열 맨 뒤의 문자 3개("  +")를빼고 가져온거임 1번 과제처럼 i를 이용해서 while문 반복하면서 애초에 string에 문자를 if문으로 구분하면서 다르게 붙혀줘도 됨
