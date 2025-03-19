#include<iostream>
using namespace std;
int main(){
    int num;
    int count=0;
    cin>>num;
    for(int i=2;i<=num;i++){
        count=0;
        for(int j=2;j<i;j++){
        if(i%j == 0){
            count++;
        }
    }
    if(count<1)
    {
        cout<<i<<" ";
    }
    }
    return 0;
}
