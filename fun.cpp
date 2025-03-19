#include<iostream>
using namespace std;

void fun(){
 static int j =0; // static variable
 // local variable int  j=0;
 j++;
 cout<<"j:"<<j<<endl;
}
int main(){
 fun();
 fun();
 fun();

}