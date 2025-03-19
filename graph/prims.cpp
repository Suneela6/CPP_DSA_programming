//greedy
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> Edge;
pair<int,vector<pair<int,int>>> primMst(int n,vector<vector<Edge>>& graph){
    vector<int> key(n,INT_MAX);
    vector<bool> inMST(n,false);
    vector<int> parent(n,-1);
    int nWeight=0;
    vector<pair<int,int>> mst;
    priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
    pq.push({0,0});
    key[0]=0;
    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u]=true;
        nWeight+=key[u];
        if(parent[u] != -1){
            mst.push_back({parent[u],u});
        }
        for(auto [weight,v] : graph[u]){
            if(!inMST[v] && weight<key[v]){
                key[v] = weight;
                parent[v] =u;
                pq.push({key[v],v});
            }
        }
    }
    return {nWeight,mst};

}
int main(){
    int n,e;
    cout<<"enter number of vertices and edges";
    cin>>n>>e;
    vector<vector<Edge>> graph(n);
    cout<<"enter the edges node , parent node,weight(w,u,v)"<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>w>>u>>v;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }
    auto [nWeight,mst] = primMst(n,graph);

    cout<<"total weight of mst:"<<nWeight<<endl;
    cout<<"edges in mst:\n";
    for(auto [u,v]:mst){
        cout<<u<<" - "<<v<<endl;
    }
    return 0;
}