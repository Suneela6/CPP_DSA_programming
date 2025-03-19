#include<iostream>
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
Node* deleteAtHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    if(head!=nullptr){
    head->prev=nullptr;
    }
    delete temp;
    return head;
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int n;
    cout<<"enter number of elements of a linked list: ";
    cin>>n;
    cout<<"enter elements of a DLL: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            tail=head;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    head=deleteAtHead(head);
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}