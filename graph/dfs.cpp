#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    void dfsOF(int node,vector<int>& visited,vector<int>& dfs,vector<int> adj[]){
        visited[node] =1;
                dfs.push_back(node);
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                dfsOF(neighbor,visited,dfs,adj);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int v,vector<int> adj[]){
        vector<int> visited(v,0);
        vector<int> dfs;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfsOF(i,visited,dfs,adj);
            }
        }
        return dfs;
    }
    
};
int main(){
    int v,e;
    cout<<"enter number of vertices and edges";
    cin>>v>>e;
    vector<int> adj[v];
    cout<<"enter the edges(u,v)";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> result = obj.dfsOfGraph(v,adj);
    cout<<"dfs of the graph is:";
    for(int node:result){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}