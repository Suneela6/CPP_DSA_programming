#include<iostream>
#include<vector>
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
        if(nodeU != nodeV){
        if(rank[nodeU]<rank[nodeV]){
            parent[nodeU] =nodeV;
        }
        else if(rank[nodeU] > rank[nodeV]){
            parent[nodeV] = nodeU;
        }
        else{
            parent[nodeV] = nodeU;
            rank[nodeU]++;
        }
    }
    }
    void display(){
        for(int i=1;i<parent.size();i++){
            cout<<"Node "<<i<<"-> parent "<<parent[i]<<endl;
        }
    }
    
};
int main()
{
    int n=7;
    DisJointSet ds(n);
    ds.unite(1,2);
    ds.unite(2,3);
    ds.unite(4,5);
    ds.unite(6,7);
    ds.unite(5,6);
    ds.unite(3,7);
    cout<<"patrent relationships after unions: "<<endl;
    ds.display();

    cout<<"find(4): "<<ds.find(4)<<endl;
    cout<<"find(2): "<<ds.find(2)<<endl;
    return 0;
    
} 