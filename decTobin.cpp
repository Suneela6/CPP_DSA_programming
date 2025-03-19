#include<iostream>
using namespace std;
int main(){
    int a[10],n,i;
    i=0;
    cout<<"enter the n to convert:";
    cin>>n;
    while(n>0){
        a[i] = n%2;
        n=n/2;
        i++;
    }
    for(i=i-1;i>=0;i--){
        cout<<a[i];
    }
}