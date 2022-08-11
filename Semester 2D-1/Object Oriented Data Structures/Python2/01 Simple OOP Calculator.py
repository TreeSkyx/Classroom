class Calculator:

    def __init__(self, a):
        self.a = a

    def __add__(self, o):
        return self.a + o.a

    def __sub__(self, o):
        return self.a - o.a

    def __mul__(self, o):
        return self.a * o.a

    def __truediv__(self, o):
        return self.a / o.a


x, y = input("Enter num1 num2 : ").split(",")

x, y = Calculator(int(x)), Calculator(int(y))

print(x + y, x - y, x * y, x / y, sep="\n")
