class Stack():

    def __init__(self, ls = None):
        if ls == None:
            self.items = []
        else:
            self.items = ls

    def isEmpty(self):
        return True if self.size() == 0 else False

    def push(self,i):
        self.items.append(i)

    def pop(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def peek(self):
        return self.items[-1]

def infix2postfix(exp) :

    s = Stack()

    ### Enter Your Code Here ###

        



print(" ***Infix to Postfix***")

token = input("Enter Infix expression : ")

print("PostFix : ")

print(infix2postfix(token))