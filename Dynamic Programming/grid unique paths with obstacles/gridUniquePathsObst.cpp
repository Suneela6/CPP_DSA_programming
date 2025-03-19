//given a 'N' * 'M' maze with obstackes,count and return the 
//number of paths to reach the right-bottom cell from the top-left cell.
//a cell in the given maze has a value-1 if it is a blockage or dead-end,
//else 0. from a given cell, we are allowed to move to cells(i+1,j) and (i,j+1) only,
//since the answer can be large, print it modulo 10^9+7
#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9 + 7;
int griduniquepaths(int m,int n,vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(m<0||n<0||grid[m][n]==-1){
        return 0;
    }
    if(m==0 && n==0){
        return 1;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    int up=(m>0) ? griduniquepaths(m-1,n,grid,dp)%MOD : 0;
    int left=(n>0) ? griduniquepaths(m,n-1,grid,dp)%MOD : 0;
    return dp[m][n]=(up+left) % MOD;
}
int main()
{
 int m=3,n=3;
 vector<vector<int>> grid = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    if (grid[0][0] == -1 || grid[m - 1][n - 1] == -1) {
        cout << "Total number of grid unique paths with obstacles is: 0" << endl;
        return 0;
    }
 vector<vector<int>> dp(m,vector<int>(n,-1));
  int ans=griduniquepaths(m-1,n-1,grid,dp);
  cout<<"total number of grid unique paths with obstacles is:"<<ans;
  return 0;
} 
