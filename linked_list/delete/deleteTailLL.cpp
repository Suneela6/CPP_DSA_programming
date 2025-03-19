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
// Node* deleteTail(Node* head){
//     if(head==NULL || head->next==NULL){
//         return NULL;
//     }
//     Node* temp=head;
//     Node* temp1=head->next;
//     while (temp1->next!=nullptr)
//     {
//         temp=temp->next;
//         temp1=temp1->next;
//     }
//     if(temp1->next == nullptr){
//         temp->next=nullptr;
//     }
//     return head;
// }
Node* deleteTail(Node* head){
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head; 
        return nullptr;
    }
    Node* temp=head;
    while (temp->next->next != nullptr)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
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
    Node* head1=deleteTail(head);
    Node* temp=head1;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}