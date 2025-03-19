//longest sub array with sum<=k
//window is of variable size
//brute-force approach
// #include<iostream>
// #include<vector>
// using namespace std;
// int longestSubarray(vector<int> arr,int k){
//     int maxlen=0;
//     for(int i=0;i<arr.size();i++){
//         int sum=0;
//         for(int j=i;j<arr.size();j++){
//             sum=sum+arr[j];
//             if(sum<=k){
//                 maxlen=max(maxlen,j-i+1);
//             }
//             else if(sum>k){
//                 break;
//             }
//         }
//     }
//     return maxlen;
// }
// int main(){
//     vector<int> arr={2,5,1,2,7,10};
//     int k=14;
//     cout<<"longest sub array: "<<longestSubarray(arr,k);
// }

// better approach
#include<iostream>
#include<vector>
using namespace std;
int longestSubarray(vector<int> arr,int k){
    int left=0,right=0,sum=0,maxlen=0;
    while (right<arr.size())
    {
        sum=sum+arr[right];
        while(sum>k){
            sum=sum-arr[left];
            left=left+1;
        }
        if(sum<=k){
            maxlen=max(maxlen,right-left+1);
        }
        right=right+1;
    }
    return maxlen;
}
int main(){
    vector<int> arr={2,5,1,2,7,10};
    int k=14;
    cout<<"longest sub array: "<<longestSubarray(arr,k);
}