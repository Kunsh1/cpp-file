class SET:
    def __init__(self, elements):
        self.set = set(elements)

    def ismember(self, element):
        return element in self.set

    def powerset(self):
        power_set = [[]]
        for i in self.set:
            for subset in power_set:
                power_set = power_set + [list(subset)+[i]]
        return power_set

    def subset(self, other):
        return self.set.issubset(other.set)
        
    def union(self, other):
        return list(self.set.union(other.set))

    def intersection(self, other):
        return list(self.set.intersection(other.set))


if __name__ == '__main__':
    element_1 = list(map(int, input('Enter elements of the first set: ').split()))
    set1 = SET(element_1)
    element_2 = list(map(int, input('Enter elements of the second set: ').split()))
    set2 = SET(element_2)
    

    while True:
        print('Menu')
        print('1. ismember\n2. powerset\n3. subset\n4. union\n5. intersection\n0. exit')
        operation = int(input('Enter the operation number: '))

        if operation == 1:
            print('1. Search from set1\n2. Search from set2')
            selection = int(input('Select Set:'))

            if selection == 1:
                print(set1.ismember(int(input('Enter element to search from set1: '))))
            elif selection == 2:
                print(set2.ismember(int(input('Enter element to search from set2: '))))
            else:
                print('Invalid Selection')

        elif operation == 2:
            print(set1.powerset())
        elif operation == 3:
            print(set1.subset(set2))
        elif operation == 4:
            print(set1.union(set2))
        elif operation == 5:
            print(set1.intersection(set2))
        elif operation == 0:
            break
        else:
            print("Invalid Input")
