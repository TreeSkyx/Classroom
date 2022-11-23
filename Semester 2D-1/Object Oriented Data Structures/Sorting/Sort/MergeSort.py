def MergeSort(array):
    if len(array) > 1 :

        # r is ratio point divided into two subarrays
        r = len(array)//2
        Left = array[:r]
        Right = array[r:]

        MergeSort(Left)
        MergeSort(Right)

        i = j = k = 0
        while i < len(Left) and j < len(Right):
            if Left[i] < Right[j]:
                array[k] = Left[i]
                i += 1
            else:
                array[k] = Right[j]
                j += 1
            k += 1
        
        while i < len(Left):
            array[k] = Left[i]
            i += 1
            k += 1
        
        while j < len(Right):
            array[k] = Right[j]
            j += 1
            k += 1

l = [3,2,5,6,8,7,1,3,10,9]
print(l)
MergeSort(l)
print(l)