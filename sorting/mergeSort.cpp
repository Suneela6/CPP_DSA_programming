#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int left=low;
    int right=mid+1;
    int temp[high-low+1];
    int i=0;
    while(left<=mid && right <= high){
        if(arr[left]<arr[right]){
            temp[i]=arr[left];
            left++;
            i++;
        }
        else{
            temp[i]=arr[right];
            right++;
            i++;
        }
    }
    while (left<=mid)
    {
        temp[i]=arr[left];
        left++;
        i++;
    }
    while (right<=high)
    {
        temp[i]=arr[right];
        right++;
        i++;
    }
    for(int j=0;j<(high-low+1);j++){
        arr[low+j]=temp[j];
    }
    
}
void mergeSort(int arr[],int low,int high){
    int mid=(low+high)/2;
    if(low==high){
        return;
    }
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
  int arr[]={14,9,15,12,6,8,13};
  int n=sizeof(arr)/sizeof(arr[0]);
  mergeSort(arr,0,n-1);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}