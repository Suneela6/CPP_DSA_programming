#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[1][0] = 5;
    arr[2][0] = 6;
    arr[2][2] = 8;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cout<< arr[i][j] + " ";
        }
        cout<<"\n";
    }
    return 0;
}


