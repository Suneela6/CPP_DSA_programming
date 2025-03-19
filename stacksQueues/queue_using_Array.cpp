#include<iostream>
using namespace std;
class Queue{
    int size1=10;
    int queue[10];
    int current_size=0;
    int start=-1;
    int end=-1;
    public:
    void push(int x){
        if(current_size==size1){
            cout<<"queue is overflow"<<endl;
            return;
        }
        if(current_size==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size1;
        }
        queue[end]=x;
        current_size+=1;
    }
    int pop(){
      if(current_size==0){
        cout<<"queueu is empty"<<endl;
        return -1;
      }  
      int el=queue[start];
      if (current_size==1)
      {
        start=end=-1;
      }
      else{
        start=(start+1)%size1;
      }
      current_size-=1;
      return el;
    }
    int top(){
        if(current_size==0){
            cout<<"queue is empty:"<<endl;
            return -1;
        }
        return queue[start];
    }
    int size(){
        return current_size;
    }
};
int main(){
    Queue q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(1);
    cout << "Popped element: " << q.pop() << endl;
    cout << "Top element: " << q.top() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Pop element is: " << q.pop() << endl;
    cout << "Size of stack: " << q.size() << endl;
    return 0;
}