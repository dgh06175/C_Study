arr = [10, 3.5, "python", 100]
arr[2] = arr[2].upper()
print(arr)
arr[1] = [1.0, 2.1, 3.1]
print(arr)
arr[1].reverse()
print(arr)
arr[1][0] = 3.5
print(arr)
arr[2] = int(arr.pop() / 2)
print(arr)
arr += [60, 70, 80]
print(arr)
print("마지막원소 추출 : " + str(arr.pop()))
print(arr)
print("index1 요소 pop추출 : " + str(arr.pop(1)))
print(arr)