#Normal 
def InsertionSort(lst):
    #Run form index [1] to last index : Card index[0] is on your hand
    for i in range(1 , len(lst)):
        element = lst[i] # new or insert element

        #find some index for element
        for j in range(i, -1, -1):
            if element < lst[j-1] and j > 0:
                #swap index
                lst[j] = lst[j-1]
            else:
                #found index for element
                lst[j] = element
                break

#Recursive
def InsertionSortRe(lst, n):
    #base case
    if n <= 1:
        return

    #Sort n-1 element
    InsertionSortRe(lst, n-1)
    last = lst[n-1]
    j = n-2

    while (j >= 0 and lst[j] > last):
        lst[j+1] = lst[j]
        j = j-1
    lst[j+1] = last


l = [5,6,9,7,3,2,1,6,5]
print(l)
InsertionSortRe(l , len(l))
print(l)

