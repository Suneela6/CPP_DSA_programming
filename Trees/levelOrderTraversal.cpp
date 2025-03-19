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
vector<vector<int>> levelOrderTraversal(Node* root){
    queue<Node*> q;
    vector<vector<int>> levelOrder;
    q.push(root);
    if(root==NULL){
        return levelOrder;
    }
    while (!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            Node* node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        levelOrder.push_back(level);
    }
    return levelOrder;
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    vector<vector<int>> levels = levelOrderTraversal(root);

    cout << "Level Order Traversal:" << endl;
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}