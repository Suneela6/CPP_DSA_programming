#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
Node* findLastRight(Node* root){
    if(root->right==NULL){
        return root;
    }
    return findLastRight(root->right);
}
Node* helper(Node* root){
    if(root->right == NULL){
        return root->left;
    }
    else if(root->left == NULL){
        return root->right;
    }
    Node* rightChild=root->right;
    Node* lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
Node* deleteNode(Node* root,int deletedNode){
    if(root==NULL){
        return NULL;
    }
    if(root->data==deletedNode){
        return helper(root);
    }
    Node* dummy=root;
    while(root != NULL){
        if(root->data > deletedNode){
        if(root->left!=NULL && root->left->data == deletedNode){
            root->left=helper(root->left);
            break;
        }
        else{
            root=root->left;
        }
    }
    else{
        if(root->right != NULL &&root->right->data == deletedNode){
            root->right=helper(root->right);
            break;
        }
        else{
            root=root->right;
        }
    }
    }
        return dummy;
}
void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    struct Node* root=new Node(9);
    root->left=new Node(8);
    root->left->left=new Node(5);
    root->left->left->left=new Node(3);
    root->left->left->right=new Node(7);
    root->left->left->left->left=new Node(2);
    root->left->left->left->right=new Node(4);
    root->left->left->left->left->left=new Node(1);
    root->left->left->right->left=new Node(6);
    root->left->left->right->right=new Node(8);
    root->right=new Node(12);
    root->right->left=new Node(10);
    root->right->right=new Node(13);
    root->right->left->right=new Node(11);
    int deletedNode;
    cout<<"enter node to be deleted: ";
    cin>>deletedNode;
    root=deleteNode(root,deletedNode);
    cout<<"inorder traversal after deletion is: ";
    inorder(root);
    cout<<endl;
    return 0;
}