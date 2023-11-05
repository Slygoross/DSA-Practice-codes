#include<iostream>
using namespace std;

#define MAX_SIZE 10

class Queue{
    private:
        int arr[MAX_SIZE];
        int front;
        int rear;

    public:
        Queue(){
            front = -1;
            rear = -1;
        }

        bool isFull(){
            if(rear == MAX_SIZE - 1){
                cout << "Queue is full" << endl;
                return true;
            }
            return false;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                cout << "Queue is empty" << endl;
                return true;
            }
            return false;
        }

        void enqueue(int x){
            if(isFull()){
                return;
            } else if(isEmpty()){
                front = rear = 0;
            } else {
                rear++;
            }

            arr[rear] = x;
        }

        int dequeue(){
            if(isEmpty()){
                return -1;
            }

            int x = arr[front];

            if(front == rear){
                front = rear = -1;
            } else {
                front++;
            }

            return x;
        }

        int peek(){
            if(isEmpty()){
                return -1;
            }

            return arr[front];
        }

        void display(){
            if(isEmpty()){
                return;
            }

            for(int i = front; i <= rear; i++){
                cout << arr[i] << " ";
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
