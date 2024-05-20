# Write a Program to accept a directed graph G and compute the in-degree and out degree of each vertex.


def compute_degrees(graph):
    in_degree = {}
    out_degree = {}

    # Initialize in-degree and out-degree dictionaries
    for vertex in graph:
        in_degree[vertex] = 0
        out_degree[vertex] = len(graph[vertex])

    # Compute in-degree
    for vertex in graph:
        for neighbor in graph[vertex]:
            in_degree[neighbor] += 1

    return in_degree, out_degree

# Example directed graph represented as a dictionary
graph = {
    'A': ['B', 'C'],
    'B': ['C'],
    'C': ['A', 'D'],
    'D': ['B']
}

in_degree, out_degree = compute_degrees(graph)

print("Vertex\tIn-Degree\tOut-Degree")

for vertex in graph:
    print(f"{vertex}\t{in_degree[vertex]}\t\t{out_degree[vertex]}")

