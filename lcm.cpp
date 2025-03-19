#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int num1,num2,gcdn=0;
    cin>>num1;
    cin>>num2;
    // int gcdAns=gcd(num1,num2);
    // cout<<gcdAns<<" ";
    // int lcmAns=(num1*num2)/gcdAns;
    // cout<<lcmAns;

    for(int i=1;i<num1&&i<num2;i++){
            if(num1%i==0 && num2%i==0){
                    gcdn=i;
            }
    }

    cout<<gcdn;
}