#include<iostream>
#include<vector>
using namespace std;
void subsequence(int index,int arr[],vector<int>& ds,int n){
    if(index==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==n){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    // Exclude the current element and move to the next
    subsequence(index+1,arr,ds,n);
    // Include the current element in the subsequence and recurse
    ds.push_back(arr[index]);
    subsequence(index+1,arr,ds,n);
    // Backtrack by removing the last element (undo the inclusion)
    ds.pop_back();
}
int main(){
    int arr[]={3,1,2};
    vector<int> ds;
    int n=3;
    cout<<"sub sequence is: "; 
    subsequence(0,arr,ds,n);
}