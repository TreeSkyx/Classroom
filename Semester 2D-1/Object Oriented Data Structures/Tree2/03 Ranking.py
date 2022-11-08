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

T = BST()
inp,key = input('Enter Input : ').split('/')
num = list(map(int, inp.split()))
for i in num:
    root = T.insert(i)
T.printTree(root)
print("--------------------------------------------------")
print('Rank of',key,": ",end='')
num.sort()
check = False
negative = False
for i in num:
    if i == int(key):
        check = True
        break
    if i < 0:
        negative = True
if check:
    for j in range(len(num)):
            if num[j] == int(key):
                if not negative:
                    print(j)
                    break
                else:
                    print(j+1)
                    break
else:
    num.insert(0,int(key))
    num.sort()
    for j in range(len(num)):
        if num[j] == int(key):
            if not negative:
                    print(j)
                    break
            else:
                print(j+1)
                break