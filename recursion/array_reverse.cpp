#include<iostream>
using namespace std;
void reverseArray(int arr[],int size){
    int first=0;
    int last=size-1;
    int temp;
    while(first<last){
        temp=arr[first];
        arr[first]=arr[last];
        arr[last]=temp;
        first++;
        last--;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//space complexity---arr[n]---0(1)
//time complexity----0(n/2)---as there is no consideration for constants---it is 0(n) 