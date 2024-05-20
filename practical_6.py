# Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency Matrix representation.

def complete_graph(adj_matrix):
    
    n = len(adj_matrix)
    
    for i in range(n):
        for j in range(i+1, n):
            if adj_matrix[i][j] == 0:
                return False
    return True

n = int(input("Enter the number of vertices in the graph: "))

print("Enter the adjacency matrix row by row (separate elements by space):")
adj_matrix = []
for i in range(n):
    row = list(map(int, input().split()))
    adj_matrix.append(row)

if complete_graph(adj_matrix):
    print("The given graph is a complete graph.")
else:
    print("The given graph is not a complete graph.")

