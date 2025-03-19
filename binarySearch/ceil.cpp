#include<iostream>
using namespace std;
int Ceil(int arr[], int x, int low, int high,int n) {
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n=5;
    int arr[]={3,5,8,15,19};
    int x=16;
    int low=0;
    int high=n-1;
    int lb=Ceil(arr,x,low,high,n);
    cout<<"ceil is the index: "<<lb;
}