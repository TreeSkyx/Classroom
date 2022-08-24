class Node:
    def __init__(self, data, next = None):
        self.data = data
        if next is None:
            self.next = None
        else:
            self.next = next

    def __str__(self):
        return str(self.data)
    
class LinkedList:
    def __init__(self, head = None):
        if head == None:
            self.head = self.tail = None
            self.size = 0
        else:
            self.head = head
            t = self.head
            self.size = 1
            while t.next != None:
                t = t.next
                self.size += 1
            self.tail = t

    def append(self, new_data):
        new_node = Node(new_data)

        if self.head is None:
            self.head = new_node
            return

        last = self.head
        while (last.next):
            last = last.next
        
        last.next = new_node
    
    def addHead(self, new_data):

        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def search(self, x):
 
        current = self.head.next
 
        while current != None:
            if current.data == x:
                return True 
             
            current = current.next
         
        return False 

    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=" ")
            if temp.next != None:
                print("<- ", end='')
            temp = temp.next

print(" *** Locomotive ***")
inp = input("Enter Input : ").split()
llist = LinkedList()
for i in inp:
    llist.append(i)

print("Before : ", end='')
llist.printList()

while llist.search('0'):
    llist.append(llist.head)
    llist.head = llist.head.next
    
print("\nAfter : ", end='')
llist.printList()
