#include<iostream>
using namespace std;
int main(){
    int n=6;
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }

    }
    if(sum == n){
        cout<<n<<"perfect num";
    }
    else{
        cout<<n<<"not perfect number";
    }
    return 0;
}