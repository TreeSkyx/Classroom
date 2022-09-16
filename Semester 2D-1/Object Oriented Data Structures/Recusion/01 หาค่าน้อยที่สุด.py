def findMin(l):
    if l == []:
        return None
    else:
        return findMin2(l, l[0])


def findMin2(l, min):
    if l == []:
        return min
    if int(l[0]) < int(min):
        min = int(l[0])
    return findMin2(l[1:],min)

inp = input("Enter Input : ").split()
print("Min :",findMin(inp))
