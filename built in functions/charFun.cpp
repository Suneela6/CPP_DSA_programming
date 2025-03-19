#include<iostream>
#include<cctype>
using namespace std;
int main(){
    // is digit checks if a character is a digit or not (eg: '0' to '0' --digits) (>10 are integers) .
    // if it is a digit returns 1 else return 0
    cout<<"is it a digit :"<<isdigit('2')<<endl;
    // Checks if c is an alphabet (A-Z, a-z)
    cout<<"is it a alphabet : "<<isalpha('a')<<endl;
    // isalnum() checks if the input is an alphabet (A-Z, a-z) or digit (0-9)
    cout<<"is it a alphabet number"<<isalnum('a')<<endl;
    //Checks if c is uppercase (A-Z)
    cout<<"is it upper case :"<<isupper('A')<<endl;
    //Checks if c is lowercase (a-z)
    cout<<"is it lower : "<<islower('a')<<endl;
    //Converts c to lowercase
    cout<<"converting to lower case : "<<tolower('A')<<endl;
    // Converts c to uppercase
    cout<<"converting to  a upper case : "<<toupper('a')<<endl;
}