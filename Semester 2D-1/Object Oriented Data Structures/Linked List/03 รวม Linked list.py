class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class LinkedLink:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def isEmpty(self):
        return self.head == None

    def __len__(self):
        return self.size

    def reverse(self):
        if self.isEmpty():
            print('List is empty')
        else:
            for i in range(len(self)):
                if self.nodeAt(i-1).next == None:
                    self.nodeAt(i).next = None
                else:    
                    self.nodeAt(i).next = self.nodeAt(i-1)

    def __str__(self):
        if self.isEmpty():
            return 'List is empty'
        cur = self.head
        s = "Merge : " + str(self.head.data) + " "
        while cur.next != None:
            s += str(cur.next.data) + " "
            cur = cur.next
        #s = s[:-2]
        return s

    def nodeAt(self, index):
        p = self.head
        for j in range(0, index):
            p = p.next
        return p
    
    def append(self, item):
        self.size += 1
        if self.isEmpty():
            self.head = Node(item)
            return
        node = self.head
        while node.next != None:
            node = node.next
        node.next = Node(item)

L = LinkedLink()
inp = input('Enter Input (L1,L2) : ').split()
L1 = inp[0].split('->')
L2 = inp[1].split('->')

print('L1    : ', end='')
for i in range(len(L1)):
    print(L1[i], end=' ')
    L.append(L1[i])
print()

print('L2    : ', end='')
for i in range(len(L2)):
    print(L2[i], end=' ')
print()

L2.reverse()
for i in range(len(L2)):
    L.append(L2[i])

print(L)