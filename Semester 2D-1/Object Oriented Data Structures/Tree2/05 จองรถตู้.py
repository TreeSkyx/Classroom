class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
    def __str__(self):
        return str(self.data)

class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        newNode = Node(data)

        if self.root is None:
            self.root = newNode
        else:
            current = self.root
            while current is not None:
                if data < current.data:
                    if current.left is not None:
                        current = current.left
                    else:
                        current.left = newNode
                        return self.root
                else:
                    if current.right is not None:
                        current = current.right
                    else:
                        current.right = newNode
                        return self.root
    
    def printTree(self, node, level = 0):
        if node != None:
            self.printTree(node.right, level + 1)
            print('     ' * level, node)
            self.printTree(node.left, level + 1)

k, bookLST = input('Enter Input : ').split('/')
bookLST = [int(e) for e in bookLST.split(' ')]
van = {}
for i in range(int(k)):
        van.update({i+1:0}) # add value
index=1
while len(bookLST) > 0:
    T=BST()
    van = dict(sorted(van.items(),key= lambda x : x[::-1]))
    for i in van.items():
        T.insert(list(i))
    T.root.data[1]+=bookLST[0]
    van[T.root.data[0]]+=bookLST[0]
    print('Customer {0} Booking Van {1} | {2} day(s)'.format(index,T.root.data[0],bookLST[0]))
    bookLST.pop(0)
    index+=1