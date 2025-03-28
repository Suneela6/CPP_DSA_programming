//IN ORDER TRAVERSAL OF BINARY TREE
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
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
int main(){
Node* root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
cout<<"pre order traversal: ";
preorder(root); 
}