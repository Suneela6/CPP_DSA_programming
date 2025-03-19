//memoization(top-down)
#include<iostream>
using namespace std;
int fib(int n,int dp[]){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    else{
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    }
    return dp[n];
}
int main(){
    int n=5;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    int fiba=fib(n,dp);
    cout<<"fibanocci of "<<n << "is"<<fiba;
    return 0;
}
