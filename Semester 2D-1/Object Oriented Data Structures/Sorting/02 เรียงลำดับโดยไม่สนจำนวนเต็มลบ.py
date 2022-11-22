def insertion_sort(array):
    for i in range(1, len(array)):
        key_item = array[i]
        if key_item >= 0:
            j = i-1
            while j >= 0 and array[j] > key_item:
                array[j+1] = array[j]
                j -= 1

            array[j+1] = key_item
        else:
            continue
    return array

def sortArray(a, n):
    ans = []
    for i in range(n):
        if a[i] >= 0:
            ans.append(a[i])

    ans = insertion_sort(ans)

    j = 0
    for i in range(n):
        if a[i] >= 0:
            a[i] = ans[j]
            j += 1
    
    for i in range(n):
        print(a[i],end = " ")

inp = input("Enter Input : ").split()
num = [int(i) for i in inp]
n = len(num)
sortArray(num,n)