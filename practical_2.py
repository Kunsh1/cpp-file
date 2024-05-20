# class Relation:
#     def __init__(self, matrix):
#         self.matrix = matrix
#         self.num_elements = len(matrix)
        
#     def reflexive_relation(self):
#         for i in range(self.num_elements):
#             if self.matrix[i][i] != 1:
#                 return False
#         return True
    
#     def symmetric_relation(self):
#         for i in range(self.num_elements):
#             for j in range(i+1, self.num_elements):
#                 if self.matrix[i][j] != self.matrix[j][i]:
#                     return False
#         return True
    
#     def antisymmetric_relation(self):
#         for i in range(self.num_elements):
#             for j in range(i+1, self.num_elements):
#                 if self.matrix[i][j] == 1 and self.matrix[j][i] == 1:
#                     return False
#         return True
    
#     def transitive_relation(self):
#         for i in range(self.num_elements):
#             for j in range(self.num_elements):
#                 for k in range(self.num_elements):
#                     if self.matrix[i][j] == 1 and self.matrix[j][k] == 1 and self.matrix[i][k] != 1:
#                         return False
#         return True
    
#     def check_relation(self):
#         if self.reflexive_relation():
#             print("The relation is Reflexive")
#         if self.symmetric_relation():
#             print("The relation is Symmetric")
#         if self.antisymmetric_relation():
#             print("The relation is Anti-symmetric")
#         if self.transitive_relation():
#             print("The relation is Transitive")
        
#         if self.reflexive_relation() and self.symmetric_relation() and self.antisymmetric_relation() and self.transitive_relation():
#             print("The relation is an Equivalence relation")
#         elif self.reflexive_relation() and self.antisymmetric_relation() and self.transitive_relation():
#             print("The relation is a Partial Order relation")
#         else:
#             print("The relation is None")







class RELATION:
    def __init__(self, matrix):
        self.matrix = matrix
        self.size = len(matrix)
        
    def is_reflexive(self):
        for i in range(self.size):
            if self.matrix[i][i] != 1:
                return False
        return True
    
    def is_symmetric(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j] != self.matrix[j][i]:
                    return False
        return True
    
    def is_antisymmetric(self):
        for i in range(self.size):
            for j in range(self.size):
                if i != j and self.matrix[i][j] == 1 and self.matrix[j][i] == 1:
                    return False
        return True
    
    def is_transitive(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j] == 1:
                    for k in range(self.size):
                        if self.matrix[j][k] == 1 and self.matrix[i][k] != 1:
                            return False
        return True
    
    def check_equivalence_or_partial_order(self):
        if self.is_reflexive() and self.is_symmetric() and self.is_transitive():
            return "Equivalence relation"
        elif self.is_reflexive() and self.is_antisymmetric() and self.is_transitive():
            return "Partial Order relation"
        else:
            return "None"

# Example usage:
relation_matrix = [
    [1, 0, 0],
    [0, 1, 0],
    [1, 0, 1]
]

relation = RELATION(relation_matrix)
print("Reflexive:", relation.is_reflexive())
print("Symmetric:", relation.is_symmetric())
print("Anti-symmetric:", relation.is_antisymmetric())
print("Transitive:", relation.is_transitive())
print("Type of relation:", relation.check_equivalence_or_partial_order())
