#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* deleteKth(Node* head, int k) {
    if (head == nullptr) {
        return nullptr; 
    }

    if (k == 1) { 
        Node* temp = head;
        head = head->next;
        delete temp; 
        return head;
    }

    Node* temp = head;
    int count = 0;
    Node* prev=NULL;

    while (temp != nullptr) {
        count++;
        if(count==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter number of elements of a linked list: ";
    cin >> n;

    cout << "Enter elements of a linked list: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    cout << "Enter position (kth) to delete: ";
    cin >> k;

    head = deleteKth(head, k); 

    cout << "Linked list after deletion: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
