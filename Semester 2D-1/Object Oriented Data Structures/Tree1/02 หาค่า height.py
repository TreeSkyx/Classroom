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


    def maxDepth(self, node):
        if node is None:
            return 0
        else:
            ldepth = self.maxDepth(node.left)
            rdepth = self.maxDepth(node.right)

            if ldepth > rdepth:
                return ldepth+1
            else:
                return rdepth+1

T = BST()
inp = [int(i) for i in input('Enter Input : ').split()]
for i in inp:
    root = T.insert(i)
#T.printTree(root)
print("Height of this tree is :", T.maxDepth(root)-1 if (T.maxDepth(root)-1)>0 else 0)
