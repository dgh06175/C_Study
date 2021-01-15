import time


class Date:
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    @staticmethod
    def now():
        t = time.localtime()
        return Date(t.tm_year, t.tm_mon, t.tm_mday)

    @staticmethod
    def tommorow():
        t = time.localtime(time.time() + 84600)
        return Date(t.tm_year, t.tm_mon, t.tm_mday)


a = Date(1967, 4, 7)
b = Date.now()
c = Date.tommorow()

print(a.year, a.month, a.day)
print(b.year, b.month, b.day)
print(c.year, c.month, c.day)
