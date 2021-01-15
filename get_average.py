def get_average(args):
    n = 0
    for v in args:
        n += v
    return n / len(args)

scores = [90, 98, 71, 72]
avg1 = get_average([100,80,70])
avg2 = get_average(scores)
print(avg1, avg2)
