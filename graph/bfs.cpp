#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
    vector<int> bfsOfGraph(int v,vector<int> adj[]){
        vector<int> visited(v,0);
        vector<int> bfs;
        visited[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node =q.front();
            q.pop();
            bfs.push_back(node);
            for(int it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
            }
        }
        return bfs;
    }
};
int main(){
    int v,e;
    cout<<"enter number of vertices and edges:";
    cin>>v>>e;
    vector<int> adj[v];
    cout<<"enter the edges(u,v)"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> result=obj.bfsOfGraph(v,adj);
    cout<<"bfs of the graph is:";
    for(int node:result){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}