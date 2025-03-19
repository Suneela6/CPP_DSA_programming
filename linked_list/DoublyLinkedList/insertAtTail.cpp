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
Node* insertAtTail(Node* head,Node* newTail,Node* &tail){ // tail is pass by ref
    tail->next=newTail;
    newTail->prev=tail;
    tail=newTail;
    
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
    cout<<"enter the val of tail to insert at back: ";
    int newVal;
    cin>>newVal;
    Node* newTail=new Node(newVal);
    head=insertAtTail(head,newTail,tail);
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
