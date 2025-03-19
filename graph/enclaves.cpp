//number of enclaves
//you are given an n*m binary matrix grid, where 0 represents sea cell and 1 represents a land cell
//a move consists of walking from one cell to another adjacent{4directionally}
//land cell or walking off the boundary of the grid
//find the number of land cells in grid for which we cannot walk off the
//boundary of tye grid in any number of moves
//example:grid[][]={{0,0,0,0},
                    //{1,0,1,0},
                    //{0,1,1,0},
                    //{0,0,0,0}}
//output:3
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<vector<int>> grid={{0,0,0,1,1},
                              {0,0,1,1,0},
                              {0,1,0,0,0},
                              {0,1,1,0,0},
                              {0,0,0,1,1}};
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> visited(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && visited[nrow][ncol]==0){
                visited[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j]==0){
                count++;
            }
        }
    }
    cout<<"number of enclaves:"<<count;
}