class Stack():

    def __init__(self, ls = None):
        if ls == None:
            self.items = []
        else:
            self.items = ls
    def push(self,i):
        self.items.append(i)

    def pop(self):
        return self.items.pop()
    
    def isEmpty(self):
        return True if self.size() == 0 else False

    def size(self):
        return len(self.items)

def postFixeval(st):

    s = Stack()

    for i in st:
        try:                    # try to add i in stack 
            s.push(int(i))      # if i isn't int type, except ValueError
        except ValueError:      # if i isn't int, it's mean i is an operator (+,-,*,/)
            x = s.pop()
            y = s.pop()
            if i == '/':
                s.push(y/x)
            else:
                chk = {'+':y+x , '-':y-x, '*':y*x}
                s.push(chk.get(i))
    return float(s.pop())
            
            

print(" ***Postfix expression calcuation***")

token = list(input("Enter Postfix expression : ").split())

print("Answer : ",'{:.2f}'.format(postFixeval(token)))
