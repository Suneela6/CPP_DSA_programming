//maximum depth / height of the binary tree
#include<iostream>
#include<math.h>
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
int depthOfBT(Node* root,int& diameter){
    if(root==NULL){
        return 0;
    }
    int lt=depthOfBT(root->left,diameter);
    int rt=depthOfBT(root->right,diameter);
    diameter=max(diameter,lt+rt);
    return 1+max(lt,rt);
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(6);
    root->right->left->left=new Node(5);
    root->right->left->left->left=new Node(9);
    root->right->right->right=new Node(7);
    root->right->right->right->right=new Node(8);
    int diameter=0;
    depthOfBT(root,diameter);
    cout<<"diameter of the binary tree :"<<diameter<<endl;
    return 0;
}