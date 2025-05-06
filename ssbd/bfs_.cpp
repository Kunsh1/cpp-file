#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class Graph {
public:
    map<int, vector<int>> adj;

    void addEdge(int u, int v, bool directed) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        for (auto node : adj) {
            cout << node.first << " -> ";
            for (auto neighbor : node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start) {
        map<int, bool> visited;
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (auto neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(2, 4, false);
    g.addEdge(3, 5, false);

    g.printGraph();
    g.bfs(1); // Start BFS from node 1

    return 0;
}
