//spiral traversal
#include<iostream>
#include<vector>
#include<queue>
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
vector<vector<int>> SpiralTraversal(Node* root){
    vector<vector<int>> zigZagAns;
    queue<Node*> q;
    if(root==NULL){
        return zigZagAns;
    }
    bool left2right=true;//treat it as flag which indicates right to left or left to right
    q.push(root);
    while (!q.empty())
    {
        int size=q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            int index=(left2right) ? i:(size-1-i);
            row[index] = node->data;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }

        }
        left2right=!left2right;
        zigZagAns.push_back(row);
    }
    return zigZagAns;
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    vector<vector<int>> res=SpiralTraversal(root);
    cout<<"the final zig zag ans is: "<<endl;
    for(vector<int> levels: res){
        for(int val:levels){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}