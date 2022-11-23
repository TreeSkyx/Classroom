#Noamal selection sort 
def SelectionSort(lst):
    # run form last index [-1] to first index [0] 
    for last in range(len(lst)-1, -1 , -1):
        biggest_number = lst[0] # biggest number
        biggest_index = 0 # index of biggest number

        # find biggest number 
        # from idx[0] to idx of biggest
        for i in range(1, last+1):
            # find more some biggest number
            if lst[i] > biggest_number:
                # update biggest number when found biggest 
                biggest_number = lst[i]
                biggest_index = i
        # swap between biggest number and last number
        lst[last] , lst[biggest_index] = lst[biggest_index] , lst[last]

#Recursive 
def swap(A, i , j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

def SelectionSortRe(A, i ,n):

    #find minimum element in list
    min = i
    for j in range(i+1, n):
        # if A[j] element is less, it is minimum
        if A[j] < A[min]:
            min = j #update index of min
            
    #swap minimum element
    swap(A, min ,i)

    if i + 1 < n:
        SelectionSortRe(A, i + 1, n)


l = [1,5,9,7,6,3,2,4,10,8]
print(l)
SelectionSortRe(l, 0, len(l))
print(l)