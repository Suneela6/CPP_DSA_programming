#include<iostream>
using namespace std;
int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cin>>n;
    int res=fib(n);
    cout<<"fibanocci of n numbbers is:"<<res;
}