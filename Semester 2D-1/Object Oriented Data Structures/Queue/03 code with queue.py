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



print("Enter code,hint : ",end='')
txt,hint = input().split(',')
q = Queue()

if hint < txt[0]:
    m = ord(txt[0])-ord(hint)
    for i in txt:
        q.enQueue(chr(ord(i)-m))
        print(q.items)
else:
    m = ord(hint)-ord(txt[0])
    for i in txt:
        q.enQueue(chr(ord(i)+m))
        print(q.items)



