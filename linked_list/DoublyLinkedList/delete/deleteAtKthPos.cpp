#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data2) {
        data = data2;
        next = nullptr;
        prev = nullptr;
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
Node* deleteAtTail(Node* head, Node*& tail) {
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* tail=head;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* newTail=tail->prev;
    newTail->next=nullptr;
    tail->prev=nullptr;
    delete tail;
    return head;
}
Node* deleteAtKthPos(Node* head,int k,Node* tail){
    if(head==NULL){
        return NULL;
    }
    int count=0;
    Node* KNode=head;
    while (KNode!=NULL)
    {
        count++;
        if(count==k){
            break;
        }
        KNode=KNode->next;
    }
    Node* back=KNode->prev;
    Node* front=KNode->next;
    if(back==NULL && front==NULL){
        return NULL;
    }
    else if(back==NULL){
        return deleteAtHead(head);
    }
    else if(front==NULL){
        return deleteAtTail(head,tail);
    }
    back->next=front;
    front->prev=back;
    KNode->next=nullptr;
    KNode->prev=nullptr;
    delete KNode;
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
    int k;
    cout<<"enter the position k to delete: ";
    cin>>k;
    head=deleteAtKthPos(head,k,tail);
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}