class SET:
    def __init__(self, elements):
        self.set = set(elements)
        
    def complement(self, universal_set):
        return list(set(universal_set)-self.set)


if __name__ == '__main__':
    elements = list(map(int, input('Enter elements of the set: ').split()))
    set1 = SET(elements)
    universal_set = list(map(int, input('Enter elements of the universal set: ').split()))
    print(set1.complement(universal_set))
