#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data2){
        data=data2;
        next=nullptr;
    }
};
Node* convert2array(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* movers=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        movers->next=temp;
        movers=movers->next;
    }
    return head;
}
int main(){
    vector<int> arr={2,3,4,5};
    Node* head=convert2array(arr);
    //TRAVERSAL IN A LINKED LIST
    Node* temp1=head;
    while(temp1 != nullptr)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
}