//detect cycle in directed graph
#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvisited){
    visited[node]=1;
    pathvisited[node]=1;
    for(auto it:adj[node]){
        if(visited[it]==0){
            if(dfs(it,adj,visited,pathvisited))
            {
                return true;
            }
        }
        else if(pathvisited[it]==1){
            return true;
        }
    }
    pathvisited[node]=0;
    return false;
}
bool detectCycle(int V,vector<vector<int>>& adj){
    vector<int> visited(V,0);
    vector<int> pathvisited(V,0);
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            if(dfs(i,adj,visited,pathvisited)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V,E;
    cout<<"enter number of vertices and edges:";
    cin>>V>>E;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }
    if(detectCycle(V,adj)){
        cout<<"cycle present";
    }
    else{
        cout<<"no cycle";
    }
    return 0;
}

//adj[v-1].push_back(u-1)======0-based index
//adj[v].push_back(u)====1-based index