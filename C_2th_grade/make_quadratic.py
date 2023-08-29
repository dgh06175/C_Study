def make_quadratic(a, b, c):
    def fn(x):
        return a * x ** 2 + b * x + c
    return fn

f1 = make_quadratic(2,4,2)
f2 = make_quadratic(1,-2,4)
print(f1(2))
print(f2(3))
