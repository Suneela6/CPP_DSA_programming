//there is a frog on the 1st step of an N stairs long staircase.
//the frog wants to reach the Nth stair.
//heights[i] is the height of the (i+1)th stair.
//if frog jumps from ith to jth stair,the energy lost in the jump is
//given by height(i-1)-height(j-1).in the frog is on ith staicase,he can hump either to (i+1)th stair or to (i+2)th stair.
//your task is to find the minimum total enerygy used by the frog to reach from 1st stair to Nth stair
#include<iostream>
#include<vector>
using namespace std;
int minCost(int index,vector<int>& heights,vector<int>& dp){
    if(index==0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int cost1=minCost(index-1,heights,dp)+abs(heights[index]-heights[index-1]);
    int cost2=INT_MAX;
    if(index>1){
        cost2=minCost(index-2,heights,dp)+abs(heights[index]-heights[index-2]);
    }
    return dp[index]=min(cost1,cost2);
}
int main(){
    vector<int> heights={10,30,40,20};
    int n=heights.size();
    vector<int> dp(n,-1);
    cout<<minCost(n-1,heights,dp)<<endl;
    return 0;
}