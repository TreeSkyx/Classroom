from itertools import count
from operator import indexOf


def length(txt): 
    if txt == '':
        return 0
    else:
        print(txt[0],end="",sep='')
        return 1 + length(txt[1:])

print("\n",length(input("Enter Input : ")),sep="")
