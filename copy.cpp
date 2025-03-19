#include<iostream>
using namespace std;
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int arr1[7];
    copy(arr,arr+6,arr1);
    for(int i=0;i<7;i++){
        cout<<arr1[i]<<endl;
    }
}