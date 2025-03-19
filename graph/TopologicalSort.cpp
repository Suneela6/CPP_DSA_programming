#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    private:
    void dfs(int i,vector<int> adj[],int visited[],stack<int>& st){
        visited[i]=1;
        for(auto it:adj[i]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        st.push(i);
    }
    public:
    vector<int> topologicalSort(int v,vector<int> adj[]){
        int visited[v]={0};
        stack<int> st;
        for(int i=0;i<v;i++){
            if(!visited[i]){
            dfs(i,adj,visited,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
int main()
{
    int n,e;
    cout<<"enter number of vertices and edges:";
    cin>>n>>e;
    vector<int> adj[n];
    cout<<"enter the edges(u,v)";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    Solution obj;
    vector<int> result=obj.topologicalSort(n,adj);
    cout<<"topological sort";
    for(int node:result){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
} 
