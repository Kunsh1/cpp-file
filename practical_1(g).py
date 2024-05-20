class SET:
    def __init__(self, elements):
        self.set = set(elements)
        
    def cartesian_product(self, other):
        return [[i, j] for i in self.set for j in other.set]
    
if __name__ == '__main__':
    element_1 = list(map(int, input('Enter elements of the set: ').split()))
    set1 = SET(element_1)
    element_2 = list(map(int, input('Enter elements of the other set: ').split()))
    set2 = SET(element_2)
    print(set1.cartesian_product(set2))