#include<iostream>
using namespace std;
int main(){
    int arr[]={15,22,1,2,99};
    int smallest=INT_MAX;
    // for(int i=0;i<5;i++){
    //     if(arr[i]<smallest){
    //         smallest=arr[i];
    //     }
    // }
    for(int i=0;i<5;i++){
    smallest=min(arr[i],smallest);
    }
    cout<<"smallest"<<smallest;
    return 0;
}