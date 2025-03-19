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
    int ceil=-1;
    while(root){
    if(root->data==key){
        ceil=root->data;
        return ceil;
    }
    if(key>root->data){
        root=root->right;
    }
    else{
        ceil=root->data;
        root=root->left;
    }
    }
    return ceil;
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
    cout<<"enter key for ceil";
    cin>>key;
    int ceilAns=floorBST(root,key);
    cout<<"floor of the bst is:"<<ceilAns;
}