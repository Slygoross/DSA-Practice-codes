#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
public:
    Node* head;

    PriorityQueue() {
        head = nullptr;
    }

    void enqueue(int data, int priority) {
        Node* temp = new Node(data, priority);
        if (head == nullptr) {
            head = temp;
            return;
        }
        if (priority > head->priority) {
            temp->next = head;
            head = temp;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr && curr->next->priority >= priority) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }

    void dequeue() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front() {
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(3, 1);
    pq.enqueue(4, 3);
    pq.enqueue(2, 2);
    pq.enqueue(5, 1);
    while (!pq.isEmpty()) {
        cout << pq.front() << " ";
        pq.dequeue();
    }
    return 0;
}
