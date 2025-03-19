#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool bfs(vector<vector<int>>& adj,vector<int>& color,int start)  {
    queue<int> q;
    color[start]=0;
    q.push(1);
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                    return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& adj, int V) {
    vector<int> color(V, -1); 
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { 
            if (!bfs(adj, color, i)) return false;
        }
    }
    return true;
}
int main(){
    int V,E;
    cout<<"enter number of vertices, edges:";
    cin>>V>>E;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans=isBipartite(adj,V);
    if(ans){
    cout<<"the graph is bipartite";
    }
    else{
        cout<<"not";
    }
    return 0;
}
