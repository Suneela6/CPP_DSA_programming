#include<iostream>
using namespace std;
int binarySearch(int arr[],int low,int high,int target){
    while(low<=high){
    int mid=low+(high-low)/2; //should be inside
    if(arr[mid]==target){
        return mid; // arr[mid] for returning target
    }
    else if(target>arr[mid]){
       return binarySearch(arr,mid+1,high,target);
    }
    else{
       return binarySearch(arr,low,mid-1,target);
    }
}
return -1;
}
int main()
{
    int n=8;
    int arr[]={3,4,6,7,9,12,16,17};
    int target;
    cout<<"enter the target: ";
    cin>>target;
    int low=0;
    int high=n-1;
    int ans=binarySearch(arr,low,high,target);
    if (ans != -1) {
        cout << "Target found at index: " << ans << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
    return 0;
} 