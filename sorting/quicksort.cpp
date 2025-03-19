#include<iostream>
using namespace std;
int quickSortPartition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<=j){
        while(arr[i]<=pivot&&i<=high){
            i++;
        }
        while (arr[j]>pivot && j>=low)
        {
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
    int partition=quickSortPartition(arr,low,high);
    quickSort(arr,low,partition-1);
    quickSort(arr,partition+1,high);
}
}
int main(){
    int n=8;
    int arr[]={4,6,2,5,7,9,1,3};
    int low=0;
    int high=n-1;
    quickSort(arr,low,high);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}