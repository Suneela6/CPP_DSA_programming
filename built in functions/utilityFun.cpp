#include<iostream>
#include<utility>
using namespace std;
int main(){
    int a=5;
    int b=6;
    swap(a,b);
    cout<<"after swapping the values of a and b are : "<<a<<" "<<b<<endl;
    pair<int,int> p=make_pair(a,b);
    cout<<"printing pair :"<<p.first<<" "<<p.second<<endl;
    cout<<"min of a and b :"<<min(a,b)<<endl;
    cout<<"max of a and b :"<<max(a,b)<<endl;
}