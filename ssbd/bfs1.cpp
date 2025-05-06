#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    public:
        map<int, vector<int>> gr1;
        void addEdge(int u, int v, bool direction){
            gr1[u].push_back(v);
            if(direction==1){
                gr1[v].push_back(u);
            }
        }
        void printGraph(){
            for(auto key:gr1){
                cout<<key.first<<"->";
                for(auto val:key.second){
                    cout<<val<<",";
                }
                cout<<endl;
            }
        }


        void bfs(map<int, bool> &visited, vector<int> &ans, int node){
            queue<int> q1;
            q1.push(node);
            visited[node] = true;

            while(!q1.empty()){
                int frontNode = q1.front();
                q1.pop();
                ans.push_back(frontNode);

                for(auto i:gr1[frontNode]){
                    if(!visited[i]){
                        q1.push(i);
                        visited[i] = true;
                    }
                }
            }
        }

        vector<int> BFSTraversal(){
            map<int, bool> visited;
            vector<int> ans;

            for(auto i:gr1){
                visited[i.first] = false;
            }

            for(auto i:gr1){
                if(!visited[i.first]){
                    bfs(visited, ans, i.first);
                }
            }

            return ans;

        }

        void dfs(map<int,bool> &visited, vector<int> &ans, int node){
            visited[node] = true;
            ans.push_back(node);

            for(auto i:gr1[node]){
                if(!visited[i]){
                    dfs(visited, ans, i);
                }
            }
        }

        vector<int> DFStraversal(){
            map<int,bool> visited;
            vector<int> ans;

            for(auto key:gr1){
                visited[key.first] = false;
            }

            for(auto key: gr1){
                if(!visited[key.first]){
                    dfs(visited, ans, key.first);
                }
            }

            return ans;
        }

};

int main(){
    Graph g1;
    g1.addEdge(2,3,0);
    g1.addEdge(3,4,0);
    g1.addEdge(3,6,0);
    g1.addEdge(6,7,0);
    // g1.addEdge(2,3,1);
    // g1.addEdge(3,4,1);

    g1.printGraph();

    vector<int> trav = g1.BFSTraversal();
    for(int i=0;i<trav.size();i++){
        cout<<trav[i]<<" ";
    }

    cout<<endl;
    cout<<"DFS Traversal: ";
    vector<int> dfstrav = g1.DFStraversal();
    for(int i=0;i<trav.size();i++){
        cout<<dfstrav[i]<<" ";
    }

    return 0;
}