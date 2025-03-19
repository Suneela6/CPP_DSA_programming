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
int maxPath(Node* root,int& maxSum){//must be int&(pass by ref) bcz we are changing the value globally if we dont use & the value wont be modified
    if(root==NULL){
        return 0;
    }
    int leftSum=max(0,maxPath(root->left,maxSum));
    int rightSum=max(0,maxPath(root->right,maxSum));
    maxSum=max(maxSum,leftSum+rightSum+root->data);
    return root->data+max(leftSum,rightSum);
}
int main()
{
    struct Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    int maxSum=INT_MIN;
    maxPath(root,maxSum);
    cout<<"maximum path sum is: "<<maxSum;
    return 0;
}