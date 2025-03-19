#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"enter age   ";
    cin>>age;
    if(age>18){
        cout<<"you are eligible to vote";
        return 0;
    }
    else{
        goto ineligible;
    }
    ineligible:
            cout<<"you are not eligible to vote";
    return 0;
}


