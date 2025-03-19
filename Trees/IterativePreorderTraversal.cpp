#include<iostream>
#include<vector>
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
vector<int> iterativePreorder(Node* root){
  vector<int> ans;
  stack<Node*> st;
  st.push(root);
  if(root==NULL){
    return ans;
  }
  while(!st.empty()){
    Node* node=st.top();
    st.pop();
    ans.push_back(node->data);
    if(node->right!=NULL){
        st.push(node->right);
    }
    if(node->left!=NULL){
        st.push(node->left);
    }
  }
  return ans;
}
int main(){
struct Node* root=new Node(1);
root->left=new Node(2);
root->right=new Node(7);
root->left->left=new Node(3);
root->left->right=new Node(4);
root->left->right->left=new Node(5);
root->left->right->right=new Node(6);
vector<int> PreorderTraversal= iterativePreorder(root);
cout<<"iterative preorder traversal:";
for(int val:PreorderTraversal){
    cout<<val<<" ";
}
return 0;
}