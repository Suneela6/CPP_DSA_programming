#include<iostream>
using namespace std;
int main(){
    int a[10][10],b[10][10],mul[10][10],i,j,k,r,c;
    cout<<"enter number of rows:";
    cin>>r;
    cout<<"enter number of columns:";
    cin>>c;
    cout<<"enter first matrix elements:\n";
    for(i=0;i<r;i++){
         for(j=0;j<c;j++){
           cin>>a[i][j];
         }
    }
    cout<<"enter second matrix elements:\n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>b[i][j];
        }
    }
    cout<<"after multiplying the elements\n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            mul[i][j]=0;
            for(k=0;k<c;k++){
                mul[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    cout<<"dispalying elements:\n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<mul[i][j]<<" ";
        }
   cout<<"\n";
    }
    return 0;
}