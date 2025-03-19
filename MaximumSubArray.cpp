// #include<iostream>
// using namespace std;
// int main()
// {
//     int n=5;
//     int arr[5]={1,2,3,4,5};
//     for(int start=0;start<n;start++){
//         for(int end=start;end<n;end++){
//             for(int i=start;i<=end;i++){
//                 cout<<arr[i];
//             }
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// } // namespace std;

#include<iostream>

using namespace std;
int main(){
    int n=5;
    //int arr[5]={1,2,3,4,5};
    int arr[5]={-8,-9,-5,-8,-1};
    int maxSum=INT_MIN;
    for(int start=0;start<n;start++){
        int currSum=0;
        for(int end=start;end<n;end++){
            currSum+=arr[end];
            maxSum=max(currSum,maxSum);
        }
    }
    cout<<"maximum arr sum is:"<<maxSum;
}