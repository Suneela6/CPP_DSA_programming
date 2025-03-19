#include<iostream>
#include<queue>
using namespace std;
class Stack{
    int size;
    queue<int> q1;
    queue<int> q2;
    public:
    Stack(){
        size=0;
    }
    void push(int x){
        q2.push(x);
        size++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        
    }
    void pop(){
        q1.pop();
        size--;
    }
    int top(){
        return q1.front();
    }
    int size1(){
        return size;
    }
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);st.pop();
    cout<<"top element: "<<st.top()<<endl;
    cout<<"size: "<<st.size1();
}