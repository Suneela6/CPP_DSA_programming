#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[6] = {1,2,-3,4,5,-6};
    any_of(arr,arr+5,[](int k){return k<0;})?
    cout<<"negative elemenets exist" :
    cout<<"no negative elements";
}