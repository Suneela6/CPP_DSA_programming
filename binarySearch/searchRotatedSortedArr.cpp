//entire arr has unique elements
//search and sorted=========binary search
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
        //left half sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target&&target<=arr[mid]){
            high=mid-1;
            }
            else{
            low=mid+1;
            }
        }
        if(arr[mid]<=arr[high]){
            if(arr[mid]<=target&&target<=arr[high]){
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
    int n=9;
    int arr[]={7,8,9,1,2,3,4,5,6};
    int target=8;
    int ans=rotatedArr(arr,n,target);
    if (ans != -1)
        cout << "Target found at index: " << ans << endl;
    else
        cout << "Target not found" << endl;
}