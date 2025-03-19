//maximum sum of non-adjacent elements
// you are given an arraylist of 'N' integers. 
//you are supposed to return the maximum
// sum of the subsequences with the constraint 
//that no two elements are adjacent in the given arraylist
#include<iostream>
#include <vector>
using namespace std;
int maxSumMemo(int index, vector<int>& arr, vector<int>& dp) {
    if (index == 0) return arr[0];
    if (index < 0) return 0;
    if (dp[index] != -1) return dp[index];

    int pick = arr[index] + maxSumMemo(index - 2, arr, dp);
    int notPick = maxSumMemo(index - 1, arr, dp);

    return dp[index] = max(pick, notPick);
}

int main() {
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << "Maximum sum (Memoization): " << maxSumMemo(n - 1, arr, dp) << endl;
    return 0;
}
//house robber is :
//mr.x is a professional robber planning to rob along a street.
//each house has a certain amount of money hidden
//all houses along this street are arranged in a ac circle
//that means the first house is the neighbor of the last one
//meanwhile adjacent houses have a secunrity system connected, and it will automatically contact the police if
//two adjacent houses were broken into on the same night
//you are given an arraylist of non-negative integers 'ARR'
//representing the amount of money of each house.
//your task is to return maximum amount of moeny mr.X can rob tonight without alerting the police