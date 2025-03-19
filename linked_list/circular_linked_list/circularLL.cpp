#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* CLL(Node* head,Node* tail){
    tail->next=head;
    return head;
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int n;
    cout<<"enter number of elements of the linked list: ";
    cin>>n;
    cout<<"enter elements of the linked list: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        Node* newNode=new Node(val);
        if(head== nullptr){
            head=newNode;
            tail=head;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    int insertVal;
    cout<<"enter the val of node to insert :";
    cin>>insertVal;
    Node* temp=CLL(head,tail);
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
