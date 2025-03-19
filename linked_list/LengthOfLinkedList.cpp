// #include<iostream>
// #include<vector>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     Node(int data2){
//         data=data2;
//         next=nullptr;
//     }
// };
// Node* convert2array(vector<int> &arr){
//     Node* head=new Node(arr[0]);
//     Node* movers=head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp=new Node(arr[i]);
//         movers->next=temp;
//         movers=movers->next;
//     }
//     return head;
// }
// int lengthOfArr(Node* head){
//     int cnt=0;
//     Node* temp=head;
//     while (temp!=nullptr)
//     {
//         temp=temp->next;
//         cnt++;
//     }
//     return cnt;
// }
// int main(){
//     vector<int> arr={2,9,0,7,5,8};
//     Node* head=convert2array(arr);
//     cout<<"length of the array is:"<<lengthOfArr(head);
// }
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data2){
        data=data2;
        next=nullptr;
    }
};
int lengthofarr(Node* head){
    int cnt=0;
    Node* temp=head;
    while (temp!=nullptr)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int n;
    cout<<"enter number of elements of a linked list:";
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        Node* newnode=new Node(value);
        if(head==nullptr){
            head=newnode;
            tail=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    cout<<"length of the array is: "<<lengthofarr(head);
    return 0;
}