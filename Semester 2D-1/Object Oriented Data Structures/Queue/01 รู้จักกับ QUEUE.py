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


txt = input("Enter Input : ").split(",")

q = Queue()
for i in range(len(txt)):
    if ' ' in txt[i]:
        ch, num = txt[i].split()
    else:
        ch = txt[i]
    if(ch == 'E'):
        q.enQueue(num)
        print(q.size())
    else:
        if q.size() > 0:
            print(q.deQueue(), 0)
        else:
            print("-1")

if q.size() > 0:
    for i in q.items:
        print(int(i),end=' ')
else:
    print("Empty")


