#include<iostream>
using namespace std;
int main(){
    int num,sum,first,last;
    cin>>num;
    last=num%10;
    while(num>=10){
        num/=10;
    }
    first=num;
    sum=first+last;
    cout<<"sum:"<<sum;
    return 0;
}