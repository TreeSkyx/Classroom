def partition(array, low, high):

    #Select the pivot element
    pivot = array[high]
    i = low -1

    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i] , array[j]) = (array[j], array[i])
    
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    
    return i + 1

def QuickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        QuickSort(array, low, pi -1)
        QuickSort(array, pi + 1, high)


l = [5,8,6,3,1,7,9,4,10,5]
size = len(l)
print(l)
QuickSort(l, 0 , size - 1)
print(l)