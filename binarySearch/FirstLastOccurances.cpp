#include<iostream>
using namespace std;
void FirstLastOccurence(int arr[],int n,int x){
    int first=-1;
    int last=-1;
    for(int i=0;i<n-1;i++){
        if(arr[i]==x){
        if(first==-1){
            first=i;
        }
        last=i;
    }
    }
    cout<<"first occurances:"<<first;
    cout<<"last occurances: "<<last;
}
int main(){
    int n=8;
    int arr[]={2,4,6,8,8,8,11,13};
    int x=8;
    FirstLastOccurence(arr,n,x);
}

//TC=0(N)