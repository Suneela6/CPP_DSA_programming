#include<iostream>
#include<stack>
using namespace std;

class queueUsingstack {
    stack<int> stackA;
    stack<int> stackB;

public:
    void push(int x) {
        stackA.push(x);
    }

    void pop() {
        if (stackB.empty()) {
            if (stackA.empty()) {
                cout << "Queue is empty!" << endl;
                return;
            }
            while (!stackA.empty()) {
                stackB.push(stackA.top());
                stackA.pop();
            }
        }
        if (!stackB.empty()) {
            cout << "Popped element: " << stackB.top() << endl;
            stackB.pop();
        }
    }

    int front() {
        if (stackB.empty()) {
            if (stackA.empty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            while (!stackA.empty()) {
                stackB.push(stackA.top());
                stackA.pop();
            }
        }
        return stackB.top();
    }

    int size() {
        return stackA.size() + stackB.size();
    }

    bool isEmpty() {
        return stackA.empty() && stackB.empty();
    }
};

int main() {
    queueUsingstack q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front element: " << q.front() << endl;
    q.pop();
    q.pop();
    cout << "Front element after pops: " << q.front() << endl;
    q.push(50);
    q.push(60);

    cout << "Size of queue: " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
