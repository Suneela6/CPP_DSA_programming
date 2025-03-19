//you have been given an N*M matrix filled with integer numbers
//find the maximum sum that can be obtained from a path
//starting from any cell in the first row to any cell in the last row
//from a cell in a row, you can move to another cell directly below that row, or diagonally below left or right.
//so from a particular cell(row,col), we can move in three directions i.e
//down:(row+1,col)
//down left :(row+1,col-1)
//down right:(row+1,col+1)
#include<iostream>
#include<vector>
using namespace std;
int maxPathSum(int row,int col,vector<vector<int>> matrix,vector<vector<int>>& dp,int n,int m){
    if(col<0 || col>=m){
        return -1e9;
    }
    if(row==0){
        return matrix[0][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int up=matrix[row][col]+maxPathSum(row-1,col,matrix,dp,n,m);
    int up_left=matrix[row][col]+maxPathSum(row-1,col-1,matrix,dp,n,m);
    int up_right=matrix[row][col]+maxPathSum(row-1,col+1,matrix,dp,n,m);
    return dp[row][col]=max(up,max(up_left,up_right));
}
int getMaxPathSum(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxSum=-1e9;
    for(int col=0;col<m;col++){
        maxSum=max(maxSum,maxPathSum(n-1,col,matrix,dp,n,m));
    }
    return maxSum;
}
int main(){
    vector<vector<int>> matrix={
        {10,2,3},
        {3,7,2},
        {8,1,5},
        {6,4,9}
    };
    cout << "Maximum Path Sum: " << getMaxPathSum(matrix) << endl;
    return 0;
}