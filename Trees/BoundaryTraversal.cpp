//anti clock wise direction
#include<iostream>
#include<vector>
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
bool isLeaves(Node* root){
    return (root->left == nullptr && root->right==nullptr);
}
void leftBoundary(Node* root,vector<int>& boundary){
    Node* curr=root->left;
    while(curr){
        if(!isLeaves(curr)){
            boundary.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
void addLeaves(Node* root,vector<int>& boundary){
    if(root==nullptr){
    return;
    }
    if(isLeaves(root)){
    boundary.push_back(root->data);
    return;
    }
    addLeaves(root->left,boundary);
    addLeaves(root->right,boundary);
}
void rightBoundary(Node* root,vector<int>& boundary){
    vector<int> temp;
    Node* curr=root->right;
    while(curr){
        if(!isLeaves(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        boundary.push_back(temp[i]);
    }
}
vector<int> BoundaryTraversal(Node* root){
    vector<int> boundary;
    if(!isLeaves(root)){
        boundary.push_back(root->data);
    }
    if(root==nullptr){
        return boundary;
    }
    leftBoundary(root,boundary);
    addLeaves(root,boundary);
    rightBoundary(root,boundary);
    return boundary;
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);
    vector<int> bou= BoundaryTraversal(root);
    cout<<"boundary traversal: ";
    for (int val:bou)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}