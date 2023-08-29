arr = list()
n = 1
while n != '0':
    n = input("정수 입력 : ")
    if n == '0':
        break
    arr += [int(n)]

print(arr)
print()
print("역순 : ", end='')
for v in arr[::-1]:
    print(str(v) + " ", end='')
print("\n")

integral = int(input("삽입 정수 : "))
index = int(input("삽입할 인덱스 : "))
if index > len(arr) or index < 0:
    print("index의 범위에 맞지 않습니다!!!")

else:
    arr.insert(index, integral)
print(arr)
print()
delete = int(input("삭제할 정수 : "))
if delete in arr:
    arr.remove(delete)
else:
    print(str(delete) + "는 존재하지 않습니다!")
print(arr)
arr.reverse()
print("역순 : " + str(arr))
arr.sort()
print("정렬 : " + str(arr))