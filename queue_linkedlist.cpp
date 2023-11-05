#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Queue{
    private:
        Node* front;
        Node* rear;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }

        void enqueue(int x){ 
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = NULL;

            if(rear == NULL){
                front = rear = newNode;
                return;
            }

            rear->next = newNode;
            rear = newNode;
        }

        int dequeue(){
            if(front == NULL){
                cout << "Queue is empty" << endl;
                return -1;
            }

            Node* temp = front;
            int x = temp->data;
            front = front->next;

            if(front == NULL)
                rear = NULL;

            delete temp;
            return x;
        }

        int peek(){
            if(front == NULL){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return front->data;
        }

        bool isEmpty(){
            return front == NULL;
        }

        void display(){
            if(front == NULL){
                cout << "Queue is empty" << endl;
                return;
            }

            Node* temp = front;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);

    q.display();

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    cout << "Front element is: " << q.peek() << endl;

    return 0;
}
