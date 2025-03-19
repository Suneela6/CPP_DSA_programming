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
Node* searchBST(Node* root,int nodeToSearch){
    while(root != NULL && root->data != nodeToSearch)
    {
        root=nodeToSearch<root->data ? root->left:root->right;
    }
    return root;
}
int main(){
    struct Node* root=new Node(8);
    root->left=new Node(5);
    root->right=new Node(12);
    root->left->left=new Node(4);
    root->left->right=new Node(7);
    root->left->right->left=new Node(6);
    root->right->left=new Node(10);
    root->right->right=new Node(14);
    root->right->right->left=new Node(13);
    int nodeToSearch;
    cout<<"enter a element to search:";
    cin>>nodeToSearch;
    Node* found=searchBST(root,nodeToSearch);
    if(found!=nullptr&& found->data == nodeToSearch){
        cout<<"element is found";
    }
    else{
        cout<<"element not found";
    }
    return 0;
}