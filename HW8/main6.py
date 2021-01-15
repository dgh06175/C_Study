import re

fp = open('8thHW.txt', 'r')
txt_data = fp.read()
start_str = input('시작 문자열 입력: ')
end_str = input('끝 문자열 입력: ')
print(start_str + '로 시작하고 ' + end_str + '로 끝나는 단어 목록')
for v in re.findall(r'\b' + start_str + r'\w*' + end_str + r'\b', txt_data):
    print(v)
