a, b = input('Enter Input : ').split('/')
a, b = [*map(int, a.split())], int(b)
l, r = max(a), sum(a)
while l <= r:
    m = (r-l)//2 + l
    i = c = 0
    while i < len(a):
        w = 0
        while i < len(a) and w + a[i] <= m:
            w, i = w + a[i], i+1
        c += 1
    if c <= b:
        r = m - 1
    else:
        l = m + 1
print(f'Minimum weigth for {b} box(es) =', l)