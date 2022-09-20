patternCount = 0
def pantip(k, n, arr, path):
    global patternCount
    if n>=len(arr):
        if k==0:
            print(*path)
            patternCount+=1
        return

    if k-arr[n]>=0:
        path.append(arr[n])
        pantip(k-arr[n],n+1,arr,path)
        path.pop()
        pantip(k,n+1,arr,path)
    else:
        pantip(k,n+1,arr,path)

    return patternCount

inp = input('Enter Input (Money, Product) : ').split('/')
arr = [int(i) for i in inp[1].split()]
pattern = pantip(int(inp[0]), 0, arr, [])
print("Krisada can purchase Product: {0} with: {1} Baht | {2} Pattern".format(arr, inp[0], pattern))