#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int> dijkstrasUsingSet(int n,vector<pair<int,int>> adj[],int src){
            vector<int> dis(n,INT_MAX);
            set<pair<int,int>> st;
            dis[src]={0};
            st.insert({0,src});
            while(!st.empty()){
                auto it=st.begin();
                int currdis=it->first;
                int currnode=it->second;
                st.erase(it);
                for(auto edge : adj[currnode]){
                    int weight=edge.second;
                    int adjnode=edge.first;
                    if(dis[currnode]+weight<dis[adjnode]){
                        if(dis[adjnode]!=INT_MAX){
                            st.erase({dis[adjnode],adjnode});
                        }
                        dis[adjnode] = dis[currnode]+weight;
                        st.insert({dis[adjnode],adjnode});
                    }
                }
            }
            return dis;
    }
};
int main(){
    int n,e;
    cout<<"enter number of vertices and edges:"<<endl;
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<e;i++){
        int u,v,w;
        cout<<"enter edges(u,v):";
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    int src;
    cout<<"enter source node/vertex";
    cin>>src;
    Solution obj;
    vector<int> result = obj.dijkstrasUsingSet(n,adj,src);
    for(int i=0;i<result.size();i++){
        if(result[i] == INT_MAX){
            cout<<"node is unreachable";
        }
        else{
            cout<<"node at "<<i<<":"<<result[i]<<endl;
        }
    }
}