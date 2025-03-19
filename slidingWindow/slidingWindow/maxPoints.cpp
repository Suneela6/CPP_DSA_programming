//maximum points you can obtain from cards
#include<iostream>
#include<vector>
using namespace std;
int maxPoints(vector<int>& arr,int k){
    int leftSum=0;
    int rightSum=0;
    int n=arr.size();
    for(int i=0;i<k;i++){
        leftSum+=arr[i];
    }
    int maxsum=leftSum;
    int rightindx=n-1;
    for(int i=k-1;i>=0;i--){
        leftSum=leftSum-arr[i];
        rightSum=rightSum+arr[rightindx];
        maxsum=max(maxsum,leftSum+rightSum);
        rightindx=rightindx-1;
    }
    return maxsum;
}
int main(){
    vector<int> arr={6,2,3,4,7,2,1,7,1};
    int k=4;
    cout<<"maximum points obtain from cards as we can take either from front or back is :"<<maxPoints(arr,k);
}