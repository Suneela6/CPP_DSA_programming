//greedy
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DisJointSet{
    private:
    vector<int> rank,parent;
    public:
    DisJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int find(int u){
        if(u!=parent[u]){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u,int v){
        int nodeU=find(u);
        int nodeV=find(v);
        if(nodeU!=nodeV){
            if(rank[nodeU]>rank[nodeV]){
                parent[nodeV] = nodeU;
            }
            else if(rank[nodeU]<rank[nodeV]){
                parent[nodeU] = nodeV;
            }
            else{
                parent[nodeV] = nodeU;
                rank[nodeU]++;
            }
        }
    }
};
pair<int,vector<pair<int,int>>> kruskalMST(int n,vector<vector<int>> edges){
    //lambda function
    sort(edges.begin(),edges.end(),[](const vector<int>& a,const vector<int>& b){
        return a[2]<b[2];
    });
    DisJointSet ds(n);
    int mstWeight=0;
    vector<pair<int,int>> mstEdges;
    for(const auto& edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        if(ds.find(u) != ds.find(v)){
            ds.unite(u,v);
            mstWeight+=w;
            mstEdges.push_back({u,v});
        }
    }
    return {mstWeight,mstEdges};
}
int main(){
int n,e;
cout<<"enter number of vertices,edges: "<<endl;
cin>>n>>e;
vector<vector<int>> edges;
cout<<"enter edges (u,v,w): "<<endl;
for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w; 
    edges.push_back({u,v,w});
}
auto [mstWeight,mstEdges] = kruskalMST(n,edges);
cout<<"total weight of the edges:"<<mstWeight<<endl;
cout<<"edges in MST:\n";
for(const auto& edges:mstEdges){
    cout<<edges.first<<" - "<<edges.second<<endl;
}
return 0 ;
}
