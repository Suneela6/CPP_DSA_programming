#include<iostream>
using namespace std;
class Stack{
    int top1=-1;
    int stack[10];
    public:
    Stack(){
        top1=-1;
    }
    void push(int x){
    if(top1 < 9) {  
            top1 = top1 + 1;
            stack[top1] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }
    void pop(){
    if (top1 < 0) {
            cout << "Stack Underflow\n";
        } else {
            top1 = top1 - 1;
        }
}
    int top(){
    if (top1 >= 0) {
            return stack[top1];  
        } else {
            cout << "Stack is empty\n";
            return -1;  
        }    
    }
    int size(){
    return top1+1;
    }
};
int main(){
    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(1);
    s.pop();
    s.top();
    s.top();
    s.pop();
    s.pop();
    cout<<"size of stack: "<<s.size();
    return 0;
}