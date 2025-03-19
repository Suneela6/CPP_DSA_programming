#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int A[]={12,14,17,17,19};  
    int n=sizeof(A)/sizeof(A[0]);
    cout<<"n is"<<n<<endl;
    int* ti=std::adjacent_find(A,A+n);  
    std::cout<<*ti;  

} 
