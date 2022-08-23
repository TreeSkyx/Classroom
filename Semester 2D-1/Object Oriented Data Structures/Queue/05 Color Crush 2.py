class Queue:
    def __init__(self,list = None):
        if list == None:
            self.items = []
        else:
            self.items = list

    def enQueue(self,i):
        self.items.append(i)

    def deQueue(self):
        return self.items.pop(0) if self.size() != 0 else 'Empty'
    
    def isEmpty(self):
        return self.items == []
    
    def size(self):
        return len(self.items)

normal, mirror = input("Enter Input (Normal, Mirror) : ").split(' ')

normal = list(normal)
mirror = list(mirror)

mBomb, nItem, item = [], 0, Queue()
for i in range(-1, -len(mirror) - 1, -1):
    mBomb.append(str(mirror[i]))
    if len(mBomb) > 2:
        if mBomb[-1] == mBomb[-2] == mBomb[-3]:
            item.enQueue(str(mirror[i]))
            nItem += 1
            for j in range(3):
                mBomb.pop()

nBomb, boom, fail = [], 0, 0
for i, data in enumerate(normal):
    nBomb.append(data)
    if len(nBomb) > 2:
        if nBomb[-1] == nBomb[-2] == nBomb[-3]:
            item_pop = item.deQueue()
            if data == item_pop:
                for j in range(2):
                    nBomb.pop()
                fail += 1
            elif item_pop == 'Empty':
                for j in range(3):
                    nBomb.pop()
                boom += 1
            else:
                nBomb.insert(-1,item_pop)    
print("NORMAL :\n", len(nBomb),sep='')
print(''.join(str(i) for i in reversed(nBomb)) if len(nBomb) != 0 else "Empty")
print(boom, "Explosive(s) ! ! ! (NORMAL)")
if fail > 0 :
    print("Failed Interrupted", fail, "Bomb(s)")
print("------------MIRROR------------\n\
: RORRIM\n",len(mBomb),sep='')
print(''.join(str(i) for i in reversed(mBomb))if len(mBomb) != 0 else "ytpmE")
print("(RORRIM) ! ! ! (s)evisolpxE",nItem)