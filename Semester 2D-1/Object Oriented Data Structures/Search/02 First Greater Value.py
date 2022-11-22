def first_greater_value(lst, key):
    lst = sorted(lst)
    for i in lst:
        if i > key:
            return i
    return "No First Greater Value"

inp = input("Enter Input : ").split('/')
lst, key_lst = list(map(int, inp[0].split())), list(map(int, inp[1].split()))
for key in key_lst:
    print(first_greater_value(lst.copy(), key))