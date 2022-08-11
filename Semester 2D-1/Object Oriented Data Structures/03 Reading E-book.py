print("*** Reading E-Book ***")
print("Text , Highlight : ", end='')
txt, hi = input().split(",")
for i in range(len(txt)):
    if txt[i] == hi:
        print("[", txt[i], "]", sep='', end='')
    else:
        print(txt[i], end='')
