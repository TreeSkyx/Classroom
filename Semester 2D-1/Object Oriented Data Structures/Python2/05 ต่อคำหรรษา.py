def display(w):
    print("'" + w + "' -> " + str(game_list))


print("*** TorKham HanSaa ***")
txt = input("Enter Input : ").split(",")
ch = []
word = []
game_list = []
word_count = 0
for i in range(len(txt)):
    if ' ' in txt[i]:
        a, b = txt[i].split()
        ch.append(a)
        word.append(b)
    else:
        ch.append(txt[i])
        word.append([])
for n in range(len(ch)):
    if ch[n] == 'P':
        if game_list == []:
            game_list.append(word[n])
            display(word[n])
        else:
            if ((word[n][0] == game_list[word_count][-2].upper()) or (word[n][0] == game_list[word_count][-2].lower())) and \
                (word[n][1] == (game_list[word_count][-1].upper()) or (word[n][1] == game_list[word_count][-1].lower())):
                game_list.append(word[n])
                display(word[n])
                word_count += 1
            else:
                print("'" + str(word[n]) + "' -> game over")
                break
    elif ch[n] == 'R':
        game_list = []
        word_count = 0
        print("game restarted")
    elif ch[n] == 'X':
        break
    else:
        print("'" + ch[n] + " " + word[n] + "'" + " is Invalid Input !!!")
        break
