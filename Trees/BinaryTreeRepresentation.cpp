#include<iostream>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
int main(){
struct Node* root=new Node(1);
root->left=new Node(3);
root->right=new Node(2);
root->left->right=new Node(5);
}