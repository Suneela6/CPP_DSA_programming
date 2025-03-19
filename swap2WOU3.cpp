#include<iostream>
using namespace std;
int main(){
    int a, b;
    cout<<"enter the a value:";
    cin>>a;
    cout<<"enter the b value:";
    cin>>b;
    cout<<"before swap the a is:"<<a<<"\n";
    cout<<"before swap the b is:"<<b<<"\n";
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"after swap the a is:"<<a<<"\n";
    cout<<"after swap the b is:"<<b<<"\n";
}