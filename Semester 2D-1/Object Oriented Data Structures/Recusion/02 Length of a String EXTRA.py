count = 0
def length(txt):
    global count
    if txt == '':
        return 0
    else:
        count += 1
        print(txt[0],end="")
        print("~" if count % 2 == 0 else "*",end="")
        return 1 + length(txt[1:])

print("\n",length(input("Enter Input : ")),sep="")
