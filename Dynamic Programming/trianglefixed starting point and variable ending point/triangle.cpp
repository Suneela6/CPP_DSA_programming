// you are given a triangular arraylist "TRIANGLE" .
// your task is to return the minimum path sum to reach from top to the bottom row.
//the triangle array will have N rows and the i-th row, where 0<=i<N will
//have i+1 elements
//you can move only to the adjacent number of row below each step. for example, if you are at index j in row i , then
//you can move to i or i+1 index in row j+1 in each step
#include<iostream>
#include<vector>
using namespace std;
int triangle(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp,int n){
    if(i==n-1){
        return arr[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int down=arr[i][j]+triangle(i+1,j,arr,dp,n);
    int diagonal=arr[i][j]+triangle(i+1,j+1,arr,dp,n);
    return dp[i][j]=min(down,diagonal);
}
int main(){
    int n=4;
    vector<vector<int>> arr={
        {1},
        {2,3},
        {3,6,7},
        {8,9,6,10}
    };
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int triangleAns=triangle(0,0,arr,dp,n);
    cout<<"the final ans is:"<<triangleAns;

    return 0;
}