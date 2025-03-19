//topological_sort:using(DFS)
//if there is an edge between u and v in a directed acyclic graph.
//the vertex u appears before v in that path
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int node,vector<int>& visited,vector<vector<int>>&adj,stack<int>&st){
    visited[node]=1;
    for(auto it:adj[node]){
        if(visited[it]==0){
            dfs(it,visited,adj,st);
        }
    }
    st.push(node);
}
vector<int> topological(vector<vector<int>>& adj,int V){
    vector<int> visited(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int V,E;
    cout<<"enter number of vertices and edges:";
    cin>>V>>E;
    vector<vector<int>> adj(V);
    for(int i=0;i<V;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>result= topological(adj,V);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}