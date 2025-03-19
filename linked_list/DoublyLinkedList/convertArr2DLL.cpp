#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int data2){
        data=data2;
        next=nullptr;
        prev=nullptr;
    }
};
Node* convert2DLL(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convert2DLL(arr);
    while (head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}