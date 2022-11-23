count = []
#Noamal for Loop - Implement
def BubbleSort(lst):
    for last in range(len(lst)-1, -1, -1):
        swaped = False
        for i in range(last):
            count.append(1)
            if lst[i] > lst[i+1]:
                lst[i] , lst[i+1] = lst[i+1], lst[i]
                swaped = True
        if not swaped:
            break


#Recursive - Implement
def swap(A, i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

def BubbleSortRe(A, n):
    for i in range(n-1):
        if A[i] > A[i+1]:
            swap(A, i , i+1)
    if n - 1 > 1:
        BubbleSortRe(A, n-1)



print(' *** Bubble sort ***')
inp = input('Enter some numbers : ').split()
inp = list(map(int, inp))
print()
BubbleSort(inp)
print(inp)
print(len(count))