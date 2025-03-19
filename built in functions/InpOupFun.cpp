#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int var;
    cout << "Enter an integer: ";
    cin>>var;
    cout<<"the output of var is:"<<var<<endl;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "The entered string is: " << str << endl;
    cout << "Formatted output using setw(10): " << setw(10) << var << endl;
    double num = 12.345678;
    cout << "Formatted floating number with setprecision(3): " << fixed << setprecision(3) << num << endl;
    return 0;
}