def sortAlphabet(arr):
    alpha = []
    for i in range(len(arr)):
        for j in range(0,len(arr[i])):
            if ord(arr[i][j]) >= 65 and ord(arr[i][j]) <= 90:
                alpha.append(arr[i][j])
            elif ord(arr[i][j]) >= 97 and ord(arr[i][j]) <= 122:
                alpha.append(arr[i][j])
    for i in range(len(alpha)-1):
        for j in range(len(alpha)-i-1):
            if alpha[j] > alpha[j+1]:
                alpha[j], alpha[j+1] = alpha[j+1], alpha[j]
                arr[j], arr[j+1] = arr[j+1], arr[j]
    
    for i in range(len(arr)):
        print(''.join(str(i) for i in arr[i]), end=' ')


inp = list(map(list, input('Enter Input : ').split()))
sortAlphabet(inp)