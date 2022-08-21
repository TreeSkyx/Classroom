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

act = {'0':"Eat", '1':"Game", '2':"Learn", '3':"Movie"}
location = {'0':"Res.", '1':"ClassR.", '2':"SuperM.", '3':"Home"}

m = Queue()
y = Queue()
mAct = Queue()
yAct = Queue()
mLo = Queue()
yLo = Queue()

for i in day:
    me, you = i.split()
    m.enQueue(me)
    y.enQueue(you)

print("My   Queue = ",end="")
for i in m.items:
    a, l = i.split(":")
    if i == m.items[0]:
        print(i,end="")
    else:
        print(',',i,end="")
    mAct.enQueue(act[a])
    mLo.enQueue(location[l])


print("\nYour Queue = ",end="")
for i in y.items:
    a, l = i.split(":")
    if i == y.items[0]:
        print(i,end="")
    else:
        print(',',i,end="")
    yAct.enQueue(act[a])
    yLo.enQueue(location[l])

print("\nMy   Activity:Location = ",end="")
for i in range(mAct.size()):
    print(mAct.items[i],":",mLo.items[i],end=", ",sep="")

print("\nYour Activity:Location = ",end="")
for i in range(yAct.size()):
    print(yAct.items[i],":",yLo.items[i],end=", ",sep="")
