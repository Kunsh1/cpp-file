#include<iostream>
#include<map>
#include<vector>
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

    void dfsHelper(int node, map<int, bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        map<int, bool> visited;
        cout << "DFS Traversal: ";
        dfsHelper(start, visited);
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
    g.dfs(1); // Start DFS from node 1

    return 0;
}
