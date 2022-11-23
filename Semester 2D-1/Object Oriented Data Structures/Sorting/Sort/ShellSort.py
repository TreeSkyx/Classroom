def ShellSort(lst, n):

    #range element at each n/2 , n/4 , n/8
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            temp = lst[i]
            j = i
            while j >= interval and lst[j - interval] > temp:
                lst[j] = lst[j - interval]
                j -= interval

            lst[j] = temp
        interval //= 2
   



l = [10,11,1,13,2,6,4,12,5,8,7,9,3]
size = len(l)
print(l)
ShellSort(l, size)
print(l)