#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num;
    cin>>num;
    int ans=0;
    int c1=0;
    int temp=num;
    while(temp>0){
        temp=temp%10;
        temp/=10;
        c1++;
    }
    while(num>0){
        int digit=num%10;
        ans +=pow(digit,c1);
        num/=10;
    }
    if(num==temp){
        cout<<"armstrong";
    }
    else{
        cout<<"not";
    }
    return 0;
}