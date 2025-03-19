#include<iostream>
#include<vector>
using namespace std;
bool dfs(vector<vector<int>>& adj,vector<int>& color,int i,int colr){
    color[i]=colr;
    for(auto it:adj[i]){
        if(color[it]==-1){
            if(!dfs(adj,color,it,!colr)){
                return false;
            }
        }
            else if(color[it]==colr){
                return false;
            }
        }
    return true;
}
bool isBipartite(vector<vector<int>>& adj,int V){
    vector<int> color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
        if(dfs(adj,color,i,0)==false){
            return false;
        }
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
