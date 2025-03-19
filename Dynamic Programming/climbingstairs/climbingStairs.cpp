//memoization(top-down)

//you have been given a number of stairs.
//initially you are at the 0th stair, 
//and you need to reach the Nth stair.
//Each time you can either climb one step or two steps.
//you are supposed to return the number of distinct ways 
//in which you can climb from 0th step to Nth step
// the above problem is similar to fibnocci
#include<iostream>
using namespace std;
int climbingstairs(int n,int dp[]){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int oneStep=climbingstairs(n-1,dp);
    int twoStep=climbingstairs(n-2,dp);
    return dp[n]=oneStep+twoStep;
}
int main(){
    int n=5;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    int ans=climbingstairs(n,dp);
    cout<<"climbing stairs:"<<n<<"steps"<<ans;
    return 0;
}