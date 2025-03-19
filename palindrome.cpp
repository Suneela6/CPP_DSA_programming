#include<iostream>
using namespace std;
int main(){
    int n,rev=0;
    cout<<"enter n value:";
    cin>>n;
    int temp = n;
    while(n>0){
        int digit  = n%10;
        rev = rev *10 + digit;
        n = n/10;
    }
    if(rev == temp){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}