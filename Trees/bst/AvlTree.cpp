#include<iostream>
using namespace std;
template<typename T> class AVLNODE{
    public:
    T key;
    AVLNODE* left;
    AVLNODE* right;
    int height;
    AVLNODE(T k)
    {
        key=k,
        left=nullptr,
        right=nullptr,
        height=1;
    }
};
template<typename T> class AVLTREE{
    private:
    AVLNODE<T>* root;
    int height(AVLNODE<T>* node){
        if(node==nullptr){
            return 0;
        }return node->height;
    }
    int balanceFactor(AVLNODE<T>* node){
        if(node==nullptr){
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    AVLNODE<T>* rightRotate(AVLNODE<T>* Y){
                                
    }
    AVLNODE<T>* insert(AVLNODE<T>* node,T key){
        if(node==nullptr){
            return new AVLNODE<Y>(key);
        }
        if(key<node->key){
            node->left=insert(node->left,key);
        }
        else if(key>node->key){
            node->right=insert(node->right,key);
        }
        else{
            return node;
        }
        node->height=1+max(height(node->left),height(node->right));
        int balance=balanceFactor(node);
        if(balance > 1 && key<node->left->key){
            return rightRotate(node);
        }
        if(balance < -1 && key>node->right->key){
            return leftRotate(node);
        }
        if(balance>1 && key>node->left->key){
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance<-1&& key<node->right->key)
        {
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
};
