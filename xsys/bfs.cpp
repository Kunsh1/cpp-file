#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int vertex;
    Node* next;
};

Node* adjList[MAX];
bool discovered[MAX];
int L[MAX][MAX];
int layerSize[MAX];
int n;

// Function to add an edge to the adjacency list (undirected)
void addEdge(int u, int v) {
    Node* newNode = new Node{v, adjList[u]};
    adjList[u] = newNode;

    newNode = new Node{u, adjList[v]};
    adjList[v] = newNode;
}

void BFS(int s) {
    for (int i = 0; i < n; i++) {
        discovered[i] = false;
    }
    discovered[s] = true;

    int i = 0;
    L[0][0] = s;
    layerSize[0] = 1;

    cout << "BFS Tree Edges:\n";

    while (layerSize[i] > 0) {
        int nextIndex = 0;
        layerSize[i + 1] = 0;

        for (int j = 0; j < layerSize[i]; j++) {
            int u = L[i][j];
            Node* ptr = adjList[u];

            while (ptr != NULL) {
                int v = ptr->vertex;
                if (!discovered[v]) {
                    discovered[v] = true;
                    cout << "(" << u << ", " << v << ")\n";

                    L[i + 1][nextIndex++] = v;
                    layerSize[i + 1]++;
                }
                ptr = ptr->next;
            }
        }

        i++;
    }
}

int main() {
    n = 6;

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);

    int startNode = 0;
    BFS(startNode);

    return 0;
}
