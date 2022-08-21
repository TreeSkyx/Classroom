class Queue:
    def __init__(self,list = None):
        if list == None:
            self.items = []
        else:
            self.items = list

    def enQueue(self,i):
        self.items.append(i)

    def deQueue(self):
        return self.items.pop(0)
    
    def isEmpty(self):
        return self.items == []
    
    def size(self):
        return len(self.items)


day = input("Enter Input : ").split(',')

act = {'0':"Eat", '1':"Game", '2':"Learn", '3':"Movie"}                # activity dict.
location = {'0':"Res.", '1':"ClassR.", '2':"SuperM.", '3':"Home"}      # loaction dict.

m = Queue()
y = Queue()
mAct = Queue()
yAct = Queue()
mLo = Queue()
yLo = Queue()

score = 0

for i in day:
    me, you = i.split()
    m.enQueue(me)
    y.enQueue(you)

print("My   Queue = ",end="")   # My Queue
for i in m.items:
    a, l = i.split(":")         # split activity and location
    if i == m.items[0]:
        print(i,end="")
    else:
        print(',',i,end="")
    mAct.enQueue(act[a])
    mLo.enQueue(location[l])

print("\nYour Queue = ",end="")     # Your Queue
for i in y.items:
    a, l = i.split(":")
    if i == y.items[0]:
        print(i,end="")
    else:
        print(',',i,end="")
    yAct.enQueue(act[a])
    yLo.enQueue(location[l])

print("\nMy   Activity:Location = ",end="")     # My Activity & Loaction
for i in range(mAct.size()):
    if(i == 0):
        print(mAct.items[i],":",mLo.items[i],end="",sep="")
    else:
        print(", ",mAct.items[i],":",mLo.items[i],end="",sep="")       # ref. activity and location using dict.

print("\nYour Activity:Location = ",end="")     # Your Activity & Loaction
for i in range(yAct.size()):
    if(i == 0):
        print(yAct.items[i],":",yLo.items[i],end="",sep="")
    else:
        print(", ",yAct.items[i],":",yLo.items[i],end="",sep="")

### Score Calculation
for i in range(mAct.size()):
    if mAct.items[i] == yAct.items[i] and mLo.items[i] == yLo.items[i]:     # same activity and loaction
        score += 4
    elif mAct.items[i] != yAct.items[i] and mLo.items[i] == yLo.items[i]:   # different activity / same  loaction
        score += 2
    elif mAct.items[i] == yAct.items[i] and mLo.items[i] != yLo.items[i]:   # same activity / different  loaction
        score += 1
    else:                                                                   # different activity and location
        score -= 5

if score >= 7:
    print("\nYes! You\'re my love! : Score is ", str(score), ".",sep="")
elif score < 7 and score > 0:
    print("\nUmm.. It\'s complicated relationship! : Score is ", str(score), ".",sep="")
elif score < 0:
    print("\nNo! We\'re just friends. : Score is ", str(score), ".",sep="")