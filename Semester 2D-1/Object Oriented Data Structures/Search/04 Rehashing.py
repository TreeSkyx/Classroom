class Hash:
    def __init__(self, table_size, max_collision, threshold=70):
        self.threshold = threshold
        self.max_collision = max_collision
        self.table_size = table_size
        self.element = []
        self.table = []
        for _ in range(table_size):
            self.table.append(None)

    def get_hash(self, key):
        return key % self.table_size

    def number_of_elements(self):
        number = 0
        for i in range(len(self.table)):
            if self.table[i] is not None:
                number += 1
        return number

    def is_full(self):
        return self.number_of_elements() == self.table_size

    def rehash(self, adding=None):
        if adding is not None:
            self.element.append(adding)

        self.table = []

        for possible_prime in range(self.table_size*2, 99999999999999):
            for i in range(2, int((((self.table_size*2))**.5)+1)):
                if possible_prime % i == 0:
                    break
            else:
                self.table_size = possible_prime
                break

        for i in range(self.table_size):
            self.table.append(None)
        for value in self.element:
            retry = 0
            hashed_index = self.get_hash(value)
            while retry < self.max_collision:
                index = (hashed_index + retry ** 2) % self.table_size
                if self.table[index] is None:
                    self.table[index] = value
                    break
                retry += 1
                print(f'collision number {retry} at {index}')


    def insert(self, value):
        print("Add :", value)

        retry = 0
        hashed_index = self.get_hash(value)
        while retry < self.max_collision:
            index = (hashed_index + retry ** 2) % self.table_size
            if self.table[index] is None:
                if (self.number_of_elements()+1) * 100 / self.table_size > self.threshold:
                    print("****** Data over threshold - Rehash !!! ******")
                    self.rehash(value)
                else:
                    self.element.append(value)
                    self.table[index] = value
                return
            retry += 1
            print(f'collision number {retry} at {index}')

        print("****** Max collision - Rehash !!! ******")
        self.rehash(value)

    def __str__(self):
        out = ''
        for i in range(self.table_size):
            out += f"#{i+1}\t{self.table[i]}\n"
        out += '----------------------------------------'
        return out


print(" ***** Rehashing *****")
control, lst = input("Enter Input : ").split('/')
table_size, max_collision, threshold = list(map(int, control.split()))
lst = list(map(int, lst.split()))
print("Initial Table :")
hash = Hash(table_size, max_collision, threshold)
print(hash)
for item in lst:
    hash.insert(item)
    print(hash)
