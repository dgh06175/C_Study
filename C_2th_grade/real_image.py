class Complex:
    def __init__(self, real, image):
        self.real = real
        self.image = image

    def __add__(self, c):
        real = self.real + c.real
        image = self.image + c.image
        return Complex(real, image)

    def __sub__(self, c):
        real = self.real - c.real
        image = self.image - c.image
        return Complex(real, image)

    def __str__(self):
        op = '+' if self.image >= 0 else '-'
        return '%d %s %di' % (self.real, op, abs(self.image))

    def __neg__(self):
        return Complex(-1 * self.real, -1 * self.image)

    def __mul__(self, c):
        real =  self.real * c.real - self.image * c.image
        image = self.real * c.image + self.image * c.real
        return Complex(real, image)

c1 = Complex(2, 3)
c2 = Complex(4, 5)

print('c1 = ', c1)
print('c2 = ', c2)
print('-c1 = ', -c1)
print('-c2 = ', -c2)
print('c1 * c2 = ', c1 * c2)
print('c1 * -c2 = ', c1 * -c2)
print((2+3j) * (4+5j))
