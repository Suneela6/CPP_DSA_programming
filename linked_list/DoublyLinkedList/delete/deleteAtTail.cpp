#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data2) {
        data = data2;
        next = nullptr;
        prev = nullptr;
    }
};

Node* deleteAtTail(Node* head, Node*& tail) {
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* tail=head;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* newTail=tail->prev;
    newTail->next=nullptr;
    tail->prev=nullptr;
    delete tail;
    return head;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;

    cout << "Enter number of elements of a linked list: ";
    cin >> n;

    cout << "Enter elements of a DLL: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    head = deleteAtTail(head, tail);

    cout << "Doubly linked list after deleting the tail: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
