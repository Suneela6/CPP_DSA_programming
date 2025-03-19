#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left = nullptr;
        right = nullptr;
    }
};
Node* insert(Node* root,Node* node){
    Node* curr=root;
    if(root==NULL){
        return node;
    }
    while(true){
        if(curr->data<=node->data) {
            if(curr->right!=NULL){
                curr=curr->right;
            }
            else{
                curr->right=node;
                break;
            }
        }
        else{
            if(curr->left!=NULL){
                curr=curr->left;
            }
            else{
                curr->left=node;
                break;
            }
        }
    } 
    return root;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}
void inorderTra(Node* root){
    if(root==NULL){
        return;
    }
    inorderTra(root->left);
    cout<<root->data<<" ";
    inorderTra(root->right);

}
int main(){
struct Node* root=new Node(4);
root->left=new Node(2);
root->right=new Node(7);
root->left->left=new Node(1);
root->left->right=new Node(3);
root->right->left=new Node(5);
int nodeIns;
cout<<"enter node to insert";
cin>>nodeIns;
struct Node* node=new Node(nodeIns);
root=insert(root,node);
inorderTra(root);
}