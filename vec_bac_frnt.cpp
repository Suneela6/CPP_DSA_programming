#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<string> str{"mango","banana","pine","kiwi"};
        cout<<"back   "<<str.back()<<endl;
        cout<<"front   "<<str.front()<<endl;
        if(str.empty()){
            cout<<"vec is empty";
        }
        else{
            cout<<"vec is not empty";
        }
    }
