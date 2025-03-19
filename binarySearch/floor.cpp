#include<iostream>
using namespace std;
int Floor(int arr[], int x, int low, int high) {
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
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
    int lb=Floor(arr,x,low,high);
    cout<<"floor is the index: "<<lb;
}