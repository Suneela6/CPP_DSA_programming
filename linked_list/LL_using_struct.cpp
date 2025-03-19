#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    Node(int val,Node* next1){
        data=val;
        next=next1;
    }
};

int main(){
    vector<int> arr={2,5,8,7};
    Node* y=new Node(arr[0],nullptr);
    cout<<y->data;
}