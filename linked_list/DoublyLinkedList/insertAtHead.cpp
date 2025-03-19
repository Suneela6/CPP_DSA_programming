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
Node* insertAtHead(Node* head,Node* newHead){
    if(head==NULL){
        return newHead;
    }
    newHead->next=head;
    head->prev=newHead;
    head=newHead;
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
    cout<<"enter the val of head to insert at front: ";
    int newVal;
    cin>>newVal;
    Node* newHead=new Node(newVal);
    head=insertAtHead(head,newHead);
    cout<<"doubly linked list (forward) :";
    Node* temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"doubly linked list (backward) :";
    temp=tail;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
    return 0;
}

// enter number of elements of a linked list: 5
// enter elements of a DLL:  1 2 3 4 5
// enter the val of head to insert at front: 6
// doubly linked list (forward) :6 1 2 3 4 5 
// doubly linked list (backward) :5 4 3 2 1 6