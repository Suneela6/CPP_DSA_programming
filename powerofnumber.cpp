#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int base,exponent;
    long long ansPow=1;
    int k=1;
    cin>>base;
    cin>>exponent;
    for(int i=1;i<=exponent;i++){
        ansPow*=base;
    }
    cout<<"ansPow:"<<ansPow<<endl;
}