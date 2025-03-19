//ninjaland is a country in the shape of a 2-dimensional grid 'GRID'
//  with 'N' rows and 'M' columns. each point in the grid has some cost associated with it
//find a path from top left i.e (0,0) to the bottom right i.e (N-1,M-1)
//which minimizes the sum of the cost of all the numbers along the path.
//you need to tell the minimum sum of that path
#include<iostream>
#include<vector>
using namespace std;
int minCostSum(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    int n = grid.size();
    int m = grid[0].size();
    if (i == n - 1 && j == m - 1) return grid[i][j];
    if (i >= n || j >= m) return INT_MAX;
    if (dp[i][j] != -1) return dp[i][j];
    //similarly we can write for up and left
    int rightMove = minCostSum(i, j + 1, grid, dp);
    int downMove = minCostSum(i + 1, j, grid, dp);
    return dp[i][j] = grid[i][j] + min(rightMove, downMove);
}
int main(){
    vector<vector<int>> grid={
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=minCostSum(0,0,grid,dp);
    cout<<"minimum sum of the path is:"<<ans<<endl;
    return 0;
}