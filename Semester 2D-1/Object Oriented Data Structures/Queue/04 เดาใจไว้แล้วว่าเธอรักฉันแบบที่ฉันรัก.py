class Queue :
    def __init__(self, items = None):
        if items == None:
            self.items = []
            self.size = 0
        else:
            self.items = items
            self.size = len(self.items)

    def __str__(self):
        return str(self.items)[1:-1]

    def enQueue(self, value):
        self.size += 1
        self.items.append(value)

    def deQueue(self):
        self.size -= 1
        return self.items.pop(0)
    
    def isEmpty(self):
        return self.size == 0

inp = input("Enter Input : ").split(',')
q1 = Queue()
q2 = Queue()

act = ['Eat', 'Game', 'Learn', 'Movie']
loc = ['Res.', 'ClassR.', 'SuperM.', 'Home']

myque = 'My   Queue ='
yourque = 'Your Queue ='
myact = 'My   Activity:Location ='
youract = 'Your Activity:Location ='
score = 0

for i in inp:
    que = i.split(' ')
    q1.enQueue(que[0])
    q2.enQueue(que[1])

while not q1.isEmpty() and not q2.isEmpty():
    que = [q1.deQueue(), q2.deQueue()]

    mydata = list(map(int, que[0].split(':')))
    yourdata = list(map(int, que[1].split(':')))

    myque += ' ' + que[0] + ','
    myact += ' ' + act[mydata[0]] + ':' + loc[mydata[1]] + ','
    yourque += ' ' + que[1] + ','
    youract += ' ' + act[yourdata[0]] + ':' + loc[yourdata[1]] + ','

    if mydata[0] == yourdata[0] and mydata[1] != yourdata[1]:
        score += 1
    elif mydata[0] != yourdata[0] and mydata[1] == yourdata[1]:
        score += 2
    elif mydata[0] == yourdata[0] and mydata[1] == yourdata[1]:
        score += 4
    else:
        score -= 5

score = ('Yes! You\'re my love!' if score >= 7 else 'Umm.. It\'s complicated relationship!' if score > 0 else 'No! We\'re just friends.') + ' : Score is ' + str(score) + '.'

print(myque[:-1])
print(yourque[:-1])
print(myact[:-1])
print(youract[:-1])
print(score) 