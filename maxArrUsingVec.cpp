// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin>>n;
     int value;
    // int arr[] ={1,2,3,4,5,6};
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>value;
        arr.push_back(value);
    }
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            cout<<"[";
            for(int i=start;i<=end;i++){
                if(i<end){
                cout<<arr[i]<<",";
                }
                else{
                   cout<< arr[i];
                }
            }
             cout<<"]";
            cout<<" ";
        }

        cout<<endl;
    }

    return 0;
}