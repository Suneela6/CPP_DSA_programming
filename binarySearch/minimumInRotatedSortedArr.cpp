#include <iostream>
using namespace std;

int findMin(int arr[], int n) {
   int low = 0, high = n - 1;
   int ans=INT_MAX;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        //if search space is already sorted
        //then always arr[low] is will be smaller
        //in the search space
        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=min(ans,arr[mid]);
        }

    } 
    return arr[ans]; // if you need index write as ans
}
int main() {
    int n = 7;
    int arr[] = {3, 4, 5, 1, 2, 3, 3};
    cout << "Minimum element: " << findMin(arr, n) << endl;
    return 0;
}