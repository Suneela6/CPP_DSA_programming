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
Node* insertKthPos(Node* head,int kthPos,Node* newNodeIns){
    if (kthPos == 0) {
        newNodeIns->next = head;
        if (head != nullptr) {
            head->prev = newNodeIns;
        }
        return newNodeIns;  
    }

    int count=0;
    Node* temp=head;
    Node* prev1=nullptr;
    while (head->next!=nullptr)
    {
        count++;
        if(count==kthPos){
            prev1->next= newNodeIns;
            newNodeIns->prev=prev1;
            newNodeIns->next=temp;
            temp->prev=newNodeIns;
        }
        else{
            temp=temp->next;
            temp->prev=prev1;
        }
    }
    return head;
}
int main()
{
    Node* head=nullptr;
    Node* tail=nullptr;
    int n;
    cout<<"enter number of elements of a DLL: ";
    cin>>n;
    cout<<"enter element of a DLL: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin>> val;
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            head=tail;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    
    }
    int kthPos;
    cout<<"enter the kth position to insert: ";
    cin>>kthPos;
    Node* newNodeIns=new Node(kthPos);
    head=insertKthPos(head,kthPos,newNodeIns);
    while (head!=nullptr)
    {
        cout<<head->data;
        head=head->next;
    }
    cout<<endl;
    return 0;
    
}