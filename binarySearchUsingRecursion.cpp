#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> vect,int target,int start,int end){
        int mid=(start+end)/2;
        if(start<=end){
        if(target>mid){
            return binarySearch(vect,target,mid+1,end);
        }
        else if(target<mid){
           return binarySearch(vect,target,start,mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> vec={1,2,3,4,5,6};
    int target=44;
    int start=0;
    int end=vec.size();
    cout<<binarySearch(vec,target,start,end);

    return 0;
}