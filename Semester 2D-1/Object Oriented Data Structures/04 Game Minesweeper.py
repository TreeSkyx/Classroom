def num_grid(lst):
    # Code Here
    for i in range(len(lst)):
        for j in range(len(lst[i])):
            if lst[i][j] == '-':
                lst[i][j] = 0
    for i in range(len(lst)):
        for j in range(len(lst[i])):
            if lst[i][j] == '#':
                if i == 0:
                    if j == 0 :
                        for k in range(2):
                            for l in range(2):
                                if lst[i + k][j + l] != '#':
                                    lst[i + k][j + l] += 1
                                else:
                                    continue
                    elif j == 4 :
                        for k in range(2):
                            for l in range(2):
                                if lst[i + k][(j - 1) + l] != '#':
                                    lst[i + k][(j - 1) + l] += 1
                                else:
                                    continue
                    else :
                        for k in range(2):
                            for l in range(3):
                                if lst[i + k][(j - 1) + l] != '#':
                                    lst[i + k][(j - 1) + l] += 1
                                else:
                                    continue
                elif i == 4:
                    if j == 0 :
                        for k in range(2):
                            for l in range(2):
                                if lst[(i - 1) + k][j + l] != '#':
                                    lst[(i - 1) + k][j + l] += 1
                                else:
                                    continue
                    elif j == 4 :
                        for k in range(2):
                            for l in range(2):
                                if lst[(i-1) + k][(j-1) + l] != '#':
                                    lst[(i-1) + k][(j-1) + l] += 1
                                else:
                                    continue
                    else :
                        for k in range(2):
                            for l in range(3):
                                if lst[(i - 1) + k][(j - 1) + l] != '#':
                                    lst[(i - 1) + k][(j - 1) + l] += 1
                                else:
                                    continue
                else:
                    if j == 0 :
                        for k in range(3):
                            for l in range(2):
                                if lst[(i - 1) + k][j + l] != '#':
                                    lst[(i - 1) + k][j + l] += 1
                                else:
                                    continue
                    elif j == 4 :
                        for k in range(3):
                            for l in range(2):
                                if lst[(i-1) + k][(j-1) + l] != '#':
                                    lst[(i-1) + k][(j-1) + l] += 1
                                else:
                                    continue
                    else :
                        for k in range(3):
                            for l in range(3):
                                if lst[(i - 1) + k][(j - 1) + l] != '#':
                                    lst[(i - 1) + k][(j - 1) + l] += 1
                                else:
                                    continue
    for i in range(len(lst)):
        for j in range(len(lst[i])):
            lst[i][j] = str(lst[i][j])
    return lst


print("*** Minesweeper ***")
print("Enter input(5x5) : ", end='')
lst_input = []

input_list = input().split(",")

for e in input_list:
    lst_input.append([i for i in e.split()])

print("\n", *lst_input, sep="\n")

print("\n", *num_grid(lst_input), sep="\n")
