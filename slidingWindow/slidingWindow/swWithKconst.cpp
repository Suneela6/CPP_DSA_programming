//sliding window problem with k as constant
#include<iostream>
#include<vector>
using namespace std;
int slidingWin(vector<int>& arr,int window){
    if(window>arr.size()){
        return -1;
    }
    int sum=0;
    for(int i=0;i<window;i++){
        sum=sum+arr[i];
    }
    int maxSum=sum;
    int left=0;
    int right=window;
    while(right<arr.size()){
        sum=sum-arr[left];
        sum=sum+arr[right];
        maxSum=max(sum,maxSum);
        left++;
        right++;
    }
    return maxSum;
}
int main(){
    vector<int> arr={2,5,6,7,8,93,-6};
    int window=4;
    cout<<"sliding window: "<<slidingWin(arr,window);
}