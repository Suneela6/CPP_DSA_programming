#include<iostream>
using namespace std;
int LowerBound(int arr[],int x,int low,int high,int n){
    int ans=n; // to return hypothetical ans as last element if nothing is present
    while (low<=high)
    {
       int mid=(low+high)/2;
       if(arr[mid]>x){
            ans=mid;
            high=mid-1;
       }
       else{
        low=mid+1;
       }
    }
    return ans;

}
int main(){
    int n=5;
    int arr[]={3,5,8,15,19};
    int x=16;
    int low=0;
    int high=n-1;
    int lb=LowerBound(arr,x,low,high,n);
    cout<<"upper bound is the index: "<<lb;
}