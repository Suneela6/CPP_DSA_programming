#include<iostream>
#include<cstring> // for c style strings like strcpy
#include<string>
using namespace std;
int main(){
    string st="suneela";
    string strcpy1;
    string conc="xyz";
    cout<<"using strlen(str) the output is :"<<strlen(st.c_str())<<endl;
    cout<<"length of the string using length() function is :"<<st.length()<<endl;
    cout << "Comparing two strings using C++'s compare(): " << st.compare("suneela") << endl;
    cout<<"comparing two strings using strcmp(str1,str2) : "<<strcmp("abc","abc")<<endl;
    // Using assignment instead of strcpy()
    strcpy1 = "sunee";
    cout << "Copying the string using assignment: " << strcpy1 << endl;
    //cout<<"copy the string1 from string2 using strcpy is :"<<strcpy(strcpy1,"sunee");
    cout<<"concatenating two strings :"<<(conc+"suni")<<endl;
    cout<<"substring is :"<<st.substr(0,3)<<endl;
    cout<<"find string is:"<<st.find("sun")<<endl;
    cout<<"replace string is:"<<st.replace(0,3,"SUNE")<<endl;
    cout<<"appending a string :"<<st.append("loki")<<endl;
}