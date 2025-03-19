#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallest=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest])
            {
                smallest=j;
            }
        }
        swap(arr[i],arr[smallest]);
    }
}
void printArray(int arr[] ,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] ={4,1,5,3,2};
    int n=5;
    selectionSort(arr,n);
    printArray(arr,n);
}