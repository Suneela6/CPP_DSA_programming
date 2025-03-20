//kahns:using(BFS)
//if there is an edge between u and v in a directed acyclic graph.
//the vertex u appears before v in that path
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfs(vector<vector<int>>& adj,vector<int>& indegree,int V){
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
            ans.push_back(i);
        }
    }
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
                ans.push_back(it);
            }
        }
    }
    return ans;
}
vector<int> topological(vector<vector<int>>& adj,int V){
    vector<int> indegree(V,0);
    vector<int> ans;
        ans= bfs(adj,indegree,V);
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