#include<iostream>
using namespace std;
void changeA(int* ptr){
    *ptr=20;
    cout<<"a val is inside changeA:"<<*ptr<<endl;
}
int main(){
    int a=10;
    changeA(&a);
    cout<<"a val is inside main:"<<a<<endl;
}