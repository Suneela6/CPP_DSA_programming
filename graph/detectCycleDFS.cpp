#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool detectCycle(int node,int parent,vector<vector<int>> &adj,int V,vector<int>& visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(detectCycle(it,node,adj,V,visited)==true){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycle(i, -1, adj,V, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    int V,E;
    cout<<"enter number of verices and edges:";
    cin>>V>>E;
    vector<vector<int>> adj(V);
    cout<<"enter edges u,v:";
    for(int i=1;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    Solution ob;
    if (ob.hasCycle(V, adj)) {
        cout << "There is a cycle in the graph\n";
    } else {
        cout << "No cycle in the graph\n";
    }
    return 0;
}