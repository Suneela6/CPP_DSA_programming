//distance of nearest cell having 0/1 in matrix
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<vector<int>> grid={{0,1,1,0}, {1,1,0,0}, {0,0,1,1}};
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    vector<vector<int>> distance(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                visited[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }
    while (!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        q.pop();
        distance[row][col]=time;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0){
                visited[nrow][ncol]=1;
                q.push({{nrow,ncol},time+1});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }
}