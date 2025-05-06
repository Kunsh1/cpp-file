#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int vertex;
    Node* next;
};

Node* adjList[MAX];
bool visited[MAX];
int n;

void addEdge(int u, int v) {
    Node* newNode = new Node{v, adjList[u]};
    adjList[u] = newNode;

    newNode = new Node{u, adjList[v]};
    adjList[v] = newNode;
}

void DFS(int u) {
    visited[u] = true;
    cout << "Visited: " << u << "\n";

    Node* ptr = adjList[u];
    while (ptr != NULL) {
        int v = ptr->vertex;
        if (!visited[v]) {
            cout << "Tree Edge: (" << u << ", " << v << ")\n";
            DFS(v);
        }
        ptr = ptr->next;
    }
}

int main() {
    n = 6;

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = false;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);

    int startNode = 0;
    DFS(startNode);

    return 0;
}
