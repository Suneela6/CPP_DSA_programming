#include<iostream>
#include<vector>
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
void inorder(Node* root,vector<int>& res){
    if(root==NULL){
        return;
    }
    inorder(root->left,res);
    res.push_back(root->data);
    inorder(root->right,res);
}
int smallOrLarge(Node* root,int kth){
    vector<int> res;
    inorder(root,res);
    if(kth>0 && kth<=res.size()){
      return res[kth-1];
    }
    return -1;
}
int main(){
 struct Node* root=new Node(5);
    root->left=new Node(3);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->left->left->right=new Node(2);
    root->right=new Node(7);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    int kth;
    cout<<"enter kth small or large element ";
    cin>>kth;
    int ans=smallOrLarge(root,kth);
    if(ans!=-1){
    cout<<"the kth small or large element is: "<<ans;
    }
    else{
        cout<<"invalid k value:";
    }
    return 0;
}

//solution 2 is : we can solve this using counter which we 
//pass through the inorder by every pass if the kth value equal 
//then we simply return . 
//in each styep we need to inc the counter