//entire arr has duplicate elements
//search and sorted=========binary search
//one more condition here is what if(arr[low]=arr[mid]=arr[high]) in this condition we may stuck and unable to find the solution so we need to solve this by low=low+1 and high=high-1
//either one half is sorted it may left or right half
//we need to check this after that
//we need to check if the target lies in left half if left half high=mid-1
// similarly we need to check if target lies in the right half , if right half low=mid+1
#include<iostream>
using namespace std;
int rotatedArr(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low=low+1;
            high=high-1;
            continue;
        }
        //left half sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target&&target<arr[mid]){
            high=mid-1;
            }
            else{
            low=mid+1;
            }
        }
        if(arr[mid]<=arr[high]){
            if(arr[mid]<target&&target<=arr[high]){
            low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int n=7;
    int arr[]={3,3,1,3,3,3,3};
    int target=1;
    int ans=rotatedArr(arr,n,target);
    if (ans != -1)
        cout << "Target found at index: " << ans << endl;
    else
        cout << "Target not found" << endl;
}