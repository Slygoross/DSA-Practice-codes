#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Stack{
    public:
        Node* top;
        Stack(){
            top = NULL;
        }

        void push(int x){
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = top;
            top = newNode;
        }

        int pop(){
            if(top == NULL){
                cout << "Stack Underflow" << endl;
                return -1;
            }

            Node* temp = top;
            int x = temp->data;
            top = top->next;
            delete temp;
            return x;
        }

        int peek(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->data;
        }

        bool isEmpty(){
            return top == NULL;
        }

        void display(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return;
            }

            Node* temp = top;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    s.display();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    s.display();

    cout << "Top element is: " << s.peek() << endl;

    return 0;
}
