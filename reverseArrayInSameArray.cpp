#include<iostream>
using namespace std;
int reverseArray(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    return 0;
}
int main(){
    int arr[]={1,5,3,8,2,9,6};
    int size=7;
    reverseArray(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}