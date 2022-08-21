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
    
    Op = set(['+','-','*','/','(',')'])         # Operator 
    priority = {'+':1, '-':1, '*':2, '/':2}     # Priority of operator
    
    ans = ''

    for i in exp:
        if i not in Op:
            ans += i
        elif i == '(':
            s.push('(')
        elif i == ')':
            while s.items and s.items[-1] != '(':
                ans += s.pop()
            s.pop()
        else:
            while s.items and s.items[-1] != '(' and priority[i]<=priority[s.items[-1]]:
                ans += s.pop()
            s.push(i)
    while s.items:
        ans += s.pop()
    
    return ans
        



print(" ***Infix to Postfix***")

token = input("Enter Infix expression : ")

print("PostFix : ")

print(infix2postfix(token))