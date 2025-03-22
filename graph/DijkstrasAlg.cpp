//dijkstras alg using pq
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution{
    public:
    vector<int> dijkstrasAlg(int n,vector<pair<int,int>> adj[],int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int disCurr=pq.top().first;
            int nodeCurr=pq.top().second;
            pq.pop();
            if(disCurr >  dis[nodeCurr]){
                continue;
            }
            for(auto edge:adj[nodeCurr]){
                int weight=edge.second;
                int ver=edge.first;
                if(dis[nodeCurr]+weight<dis[ver]){
                    dis[ver] = dis[nodeCurr]+weight;
                    pq.push({dis[ver],ver});
                }
            }
        }
        return dis;
    }
};
int main(){
    int n,e;
    cout<<"enter number of vertices and edges in a graph";
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    int u,v,w;
    cout<<"enter the edges(u,v,w)"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    int src;
    cout<<"enter the source vertex";
    cin>>src;
    Solution obj;
    vector<int> result=obj.dijkstrasAlg(n,adj,src);
    cout << "Shortest distances from the source " << src << ":\n";
    for (int i = 0; i < result.size(); i++) {
    if (result[i] == INT_MAX) {
        cout << "Node " << i << ": INF (unreachable)" << endl; // Handle unreachable nodes
    } else {
        cout << "Node " << i << ": " << result[i] << endl;
    }
    }
    cout<<endl;
    return 0;
}
