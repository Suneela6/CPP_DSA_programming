#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int> bellmanFord(int n,vector<vector<int>> edges,int src){
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        for(int i=0;i<n-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(dis[u] != INT_MAX && dis[u]+w<dis[v]){
                        dis[v] = dis[u]+w;
                }
            }
        }
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dis[u] != INT_MAX && dis[u] + w < dis[v]) {
                cout << "Graph contains a negative-weight cycle\n";
                return {};
            }
        }
        return dis;
    }
};
int main(){
    int n,e;
    cout<<"enter number of vertices aqnd edges: ";
    cin>>n>>e;
    vector<vector<int>> edges;
    cout<<"enter the u,v,w of(u,v,w):\n";
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;
    cout<<"enter source: ";
    cin>>src;
    Solution obj;
    vector<int> result=obj.bellmanFord(n,edges,src);
    cout<<"the bellman ford alg :"<<endl;;
    for(int i=0;i<result.size();i++){
        if(result[i] == INT_MAX){
            cout<<"node"<<i<<"unreachable\n";
        }
        else{
            cout<<"the node at"<<i<<":"<<result[i]<<endl;
        }
    }
    return 0;
}