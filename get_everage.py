def get_average(*args):
    t = 0
    count = 0
    for a in args:
        count = count + 1
    for v in args:
        t += v
    return t / count

scores = [90, 98, 71, 72]
avg1 = get_average(100, 80, 70)
avg2 = get_average(*scores)

print(avg1, avg2)
