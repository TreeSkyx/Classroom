class Node:
    def __init__(self, data): 
        self.data = data  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.data) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None
        self.size = 0

    def insert(self, data):  
        if self.root is None:
            self.root = Node(data)
            self.size+=1
        else:
            self._insert(data,self.root)
        return self.root
    
    def _insert(self,data,currentNode):
        if data<currentNode.data:
            if currentNode.left==None:
                currentNode.left = Node(data)
                self.size+=1
            else:
                self._insert(data,currentNode.left)
        elif data>currentNode.data:
            if currentNode.right==None:
                currentNode.right = Node(data)
                self.size+=1
            else:
                self._insert(data,currentNode.right)


    def delete(self,r, data):
        
        if self.size == 1:
                    self.root = None
                    return 
        if r is None:
            print('Error! Not Found DATA')
            return r

        else:
            if data < r.data:
                r.left = self.delete(r.left,data)
                return r

            elif data > r.data:
                r.right =self.delete(r.right,data)
                return r

            elif data == r.data:
                if r.left is None:
                    temp = r.right
                    r = None
                    return temp
                elif r.right is None:
                    temp = r.left
                    r = None
                    return temp
                
                temp = minValueNode(r.right)
                r.data = temp.data
                r.right = self.delete(r.right,temp.data)
                self.size-=1

            return r

def printTree90(node, level = 0):
    if node != None:
        printTree90(node.right, level + 1)
        print('     ' * level, node)
        printTree90(node.left, level + 1)

def minValueNode(node):
    current = node
    if current is None:
        return None
  
    while(current.left is not None):
        current = current.left
  
    return current


tree = BinarySearchTree()
data = input("Enter Input : ").split(",")
root = None
for x in data:
    action,num = x.split()
    if action[0] == 'i':
        print('insert '+num)
        root = tree.insert(int(num))
        printTree90(root)
    elif action[0] == 'd':
        print('delete '+num)
        if root is None:
            print('Error! Not Found DATA')
        else:
            root = tree.delete(root,int(num))
            printTree90(root)