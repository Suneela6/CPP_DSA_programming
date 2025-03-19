#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"enter n value";
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n-i+1;j++){
             cout<<"*";
    }
    cout<<"\n";
}

}