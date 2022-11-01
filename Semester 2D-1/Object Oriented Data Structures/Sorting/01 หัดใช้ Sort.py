inp = input("Enter Input : ").split()
num = [int(i) for i in inp]
check = 0
for x in range(len(num)-1):
    if num[x] > num[x+1]:
        print("No")
        break
    else:
        check += 1
if check == len(num)-1:
    print("Yes")
        

    