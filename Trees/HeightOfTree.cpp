//maximum depth / height of the binary tree
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
int depthOfBT(Node* root){
    if(root==NULL){
        return 0;
    }
    int lt=depthOfBT(root->left);
    int rt=depthOfBT(root->right);
    return 1+max(lt,rt);
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->right=new Node(6);
    root->left->right->right->right=new Node(7);
    int dp=depthOfBT(root);
    cout<<"depth of the binary tree is:"<<dp<<endl;;
    return 0;
}