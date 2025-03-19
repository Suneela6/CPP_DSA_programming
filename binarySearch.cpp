#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> vect,int target){
    int start=0;
    int end=vect.size();
    while(start<=end){
        int mid=(start+end)/2;
        if(target>mid){
            start=mid+1;
        }
        else if(target<mid){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> vec={1,2,3,4,5,6};
    int target=4;
    cout<<binarySearch(vec,target);

    return 0;
}