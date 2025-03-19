// #include<iostream>
// using namespace std;
// void Names(){
//     cout<<"suneela";
//     Names();
// }
// int main(){
//     Names();
// }
#include<iostream>
using namespace std;
void names(int n,int count){
    if(count==n){
        return;
    }
    cout<<"suneela"<<" ";
    names(n,count+1);
}
int main(){
    int n;
    int count=0;
    cin>>n;
    names(n,count);
}