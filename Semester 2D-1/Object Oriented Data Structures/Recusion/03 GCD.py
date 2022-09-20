def GCD(x,y):
    r=x%y
    if(r==0):
        return y
    else:
        return GCD(y,r)

x,y = input("Enter Input : ").split()
if(x == '0' and y == '0'):
    print("Error! must be not all zero.")
else:
    if (int(x)>int(y)):
        print("The gcd of",x, "and",y, "is :", abs(GCD(int(x),int(y))))
    else:
        print("The gcd of",y, "and",x, "is :", abs(GCD(int(x),int(y))))