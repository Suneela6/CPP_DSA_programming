#include<iostream>
using namespace std;
int main(){
    int num,isPrime=true;
    cin>>num;
    for(int i=2;i*i<num;i++){
        if(num%i == 0){
            isPrime=false;
            break;
        }
        else{
            isPrime=true;
        }
    }
    if(isPrime){
        cout<<"prime number"<<endl;
    }
    else{
        cout<<"not prime"<<endl;
    }
    return 0;
}