def odd_even(arr, s):
    lst = []
    for x in range(len(arr)):
        if s == "Odd":
            if (x + 1) % 2 != 0:
                if type(arr) == list:
                    lst.append(arr[x])
                else:
                    print(arr[x], end='')
        else:
            if (x + 1) % 2 == 0:
                if type(arr) == list:
                    lst.append(arr[x])
                else:
                    print(arr[x], end='')

    if type(arr) == list:
        print(list(lst))


print("*** Odd Even ***")
txt_type, txt, n = input("Enter Input : ").split(",")
if txt_type == 'S':
    odd_even(txt, n)
else:
    txt_list = txt.split()
    odd_even(txt_list, n)
