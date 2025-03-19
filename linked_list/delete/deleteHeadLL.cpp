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
Node* deleteHead(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    // temp->next=nullptr;
    //delete temp;
    free(temp);
    return head;
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int n;
    cout<<"enter number of elements of a linked list: ";
    cin>>n;
    cout<<"enter elements of a linked list: ";
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
            tail=newNode;
        }
    }
    Node* head1=deleteHead(head);
    Node* temp=head1;
    while(head!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}