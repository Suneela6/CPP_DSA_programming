#include<iostream>
using namespace std;
void changeA(int a){
    a=20;
    cout<<"a val is inside changeA:"<<a<<endl;
}
int main(){
    int a=10;
    changeA(a);
    cout<<"a val is inside main:"<<a<<endl;
}