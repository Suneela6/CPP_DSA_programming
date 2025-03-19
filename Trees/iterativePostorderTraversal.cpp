#include<iostream>
#include<stack>
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
stack<Node*> postOrderTraversal(Node* root){
    stack<Node*> st1;
    stack<Node*> st2;
    if(root==NULL){
        return st2;
    }
    st1.push(root);
    while(!st1.empty()){
        Node* node=st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=NULL){
            st1.push(node->left);
        }
        if(node->right!=NULL){
            st1.push(node->right);
        }
    }
    return st2;
}
int main(){
struct Node* root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->right->left=new Node(6);
root->right->left->right=new Node(7);
root->right->left->right->right=new Node(8);
stack<Node*> res=postOrderTraversal(root);
while(!res.empty()){
    Node* node=res.top();
    cout<<node->data<<" ";
    res.pop();
}
return 0;
}