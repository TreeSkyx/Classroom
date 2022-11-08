if __name__ == "__main__":
    inp_ = input("Enter Input : ").split('/')
    lst = list(map(int, inp_[0].split()))
    print(sum(lst))
    for q in inp_[1].split(','):
        x,y = list(map(int, q.split()))
        temp1 = lst[x] 
        if 2*x+1 < len(lst):
            temp1 += lst[2*x+1]
        if 2*x+2 < len(lst):
            temp1 += lst[2*x+2]
        temp2 = lst[y]
        if 2*y+1 < len(lst):
            temp2 += lst[2*y+1]
        if 2*y+2 < len(lst):
            temp2 += lst[2*y+2]
        print(x, end='')
        if temp1 == temp2:
            print("=", end='')
        elif temp1<temp2:
            print("<", end='')
        else:
            print(">", end='')
        print(y)