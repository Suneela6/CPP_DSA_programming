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
Node* insertHead(Node* head,Node* newNodeVal){
        if(head==NULL){
            return newNodeVal;
        }
        Node* temp=head;
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newNodeVal;
        return head;
}
// Node* insertTail(Node* head,Node* newNodeVal,Node* &tail){
//         if(head==NULL){
//             return newNodeVal;
//         }
//         tail->next=newNodeVal;
//         tail=newNodeVal;
//         return head;
// }
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
    Node* newNodeVal=new Node(insertVal);
    Node* temp=insertHead(head,newNodeVal);
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

