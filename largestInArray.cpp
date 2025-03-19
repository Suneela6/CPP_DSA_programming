#include<iostream>
using namespace std;
int main(){
    int arr[]={15,22,1,2,99};
    int largest=INT_MIN;
    // for(int i=0;i<5;i++){
    //     if(arr[i]>smallest){
    //         smallest=arr[i];
    //     }
    // }
    for(int i=0;i<5;i++){
    largest=max(arr[i],largest);
    }
    cout<<"smallest"<<largest;
    return 0;
}