def my_join(deli, obj):
    for v in obj:
        print(v, deli)



seq1 = ['홍길동', 20, True]
seq2 = ['심청이', None, 3.3]

print(my_join('-', seq1))  # 홍길동-20-True
print(my_join('!!!', seq2))  # 심청이!!!None!!!3.3
