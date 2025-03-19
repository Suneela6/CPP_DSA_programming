#include<iostream>
using namespace std;
void one2n(int n,int count){
    if(count>n){
        return;
    }
    cout<<count<<" ";
    one2n(n,count+1);
}
int main(){
    int n;
    cin>>n;
    int count=1;
    one2n(n,count);
}