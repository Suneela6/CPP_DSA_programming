#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
bool searchElement(Node* head,int key){
    while (head!=nullptr)
    {
        Node* temp=head;
        if(temp->data==key){
            return true;
        }
        else{
            temp=temp->next;
        }
    }
    return false;
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int n;
    cout<<"enter number of elements of a linked list: ";
    cin>>n;
    int key;
    cout<<"enter element to search in ll: ";
    cin>>key;
    cout<<"enter elements of a linked list: ";
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        Node* newNode=new Node(value);
        if(head==nullptr){
            head=newNode;
            tail=head;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    bool found=searchElement(head,key);
    if(found){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not existed"<<endl;
    }
    return 0;
}