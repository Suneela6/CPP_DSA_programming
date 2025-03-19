#include<iostream>
using namespace std;
void n2one(int n,int count){
    if(count<1)
    {
        return;
    }
    cout<<count<<" ";
    n2one(n,count-1);
}
int main(){
    int n;
    cin>>n;
    int count=n;
    n2one(n,count);
}