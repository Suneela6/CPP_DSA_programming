//you are present at point 'A' which is the top-left cell of an M*N matrix,
//your destination is the bottom-right cell of the same matrix.
//your task is to find the total number of
//unique paths from point 'A' to point 'B' .
//in other words , you will be given the dimensions of the matrix as integets 'M' and 'N',
//your task is to find the total number oif unique opaths from the cell matrix[0][0] to matrix[M-1][N-1]
//to traverse in the matrix, you can either move right or down at each step.
//for example in a given point matrix[i][j] , you can either matrix[i+1][j] or matrix[i][j+1]
#include<iostream>
#include<vector>
using namespace std;
int uniquePaths(int m,int n,vector<vector<int>>& dp){
    if(m==1 || n==1){
        return 1;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    int up=uniquePaths(m-1,n,dp);
    int left=uniquePaths(m,n-1,dp);
    return dp[m][n]=up+left;
}
int main(){
    int m=2,n=2;
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    int ans=uniquePaths(m,n,dp);
    cout<<"total number of unique paths is:"<<ans;
    return 0;
}