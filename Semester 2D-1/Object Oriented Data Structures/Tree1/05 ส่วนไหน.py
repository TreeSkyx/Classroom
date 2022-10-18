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
    def checkNodeExits(self, node, key):
        if node == None:
            return False
        if node.data == key:
            return True

        res1 = self.checkNodeExits(node.left,key)

        if res1:
            return True

        res2 = self.checkNodeExits(node.right,key)
        return res2

    def checkpos(self, key):
        if self.root.data == key:
            print('Root')
        elif not self.checkNodeExits(root,key):
            print('Not exist')
        else:
            current = self.root
            while current is not None:
                if key == current.data:
                    return print('Leaf') if current.left is None and current.right is None else print('Inner')
                elif key < current.data:
                    current = current.left
                elif key > current.data:
                    current = current.right
                else:
                    return root

    def printTree(self, node, level = 0):
        if node != None:
            self.printTree(node.right, level + 1)
            print('     ' * level, node)
            self.printTree(node.left, level + 1)

T = BST()
inp = [int(i) for i in input('Enter Input : ').split()]
for i in range(1, len(inp)):
    root = T.insert(inp[i])
T.printTree(root)
T.checkpos(inp[0])