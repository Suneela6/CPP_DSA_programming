#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
int floorBST(Node* root,int key){
    int floor=-1;
    while(root){
    if(root->data==key){
        floor=root->data;
        return floor;
    }
    if(key>root->data){
        floor=root->data;
        root=root->right;
    }
    else{
        root=root->left;
    }
    }
    return floor;
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->left=new Node(2);
    root->left->right=new Node(8);
    root->left->right->left=new Node(6);
    root->right->left=new Node(13);
    root->right->right=new Node(17);
    int key;
    cout<<"enter key for floor";
    cin>>key;
    int floorAns=floorBST(root,key);
    cout<<"floor of the bst is:"<<floorAns;
}