#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
class Stack{
    Node* top1=nullptr;
    public:
    void push(int x){
        Node* temp=new Node(x);
        temp->next=top1;
        top1=temp;
    }
    void pop(){
        if (top1 == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp=top1;
        top1=top1->next;
        delete temp;
    }
    int top(){
        if (top1 == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top1->data;
    }
    int size(){
        int count=0;
        Node* temp=top1;
        while (temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
};
int main(){
    Stack s;
    s.push(4);
    s.push(2);
    s.push(3);
    s.push(1);
    cout << "Top element: " << s.top() << endl;  
    s.pop(); 
    cout << "Top element after pop: " << s.top() << endl;  
    s.push(7); 
    cout << "Size of stack: " << s.size() << endl;  
    return 0;
}