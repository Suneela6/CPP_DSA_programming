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
bool Identical2Tress(Node* root1,Node* root2){
    if(root1==root2){
        return (root1==root2);
    }
    return (root1->data==root2->data) && Identical2Tress(root1->left,root2->left) && Identical2Tress(root1->right,root2->right);//preorder traversal
    
}
int main(){
    struct Node* root1=new Node(1);
    struct Node* root2=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->right->left=new Node(4);
    root1->right->right=new Node(5);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->right->left=new Node(4);
    root2->right->right=new Node(5);
    bool iden=Identical2Tress(root1,root2);
    if(iden){
        cout<<"two trees are identical ";
    }
    else{
        cout<<"not identical ";
    }
    return 0;
}