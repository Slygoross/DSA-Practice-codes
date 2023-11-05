#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
public:
    int top; // Index of the top element
    int arr[MAX_SIZE]; // Array to hold the elements

    // Constructor
    Stack() {
        top = -1; // Set the initial value of top to -1
    }

    // Push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }

        int popped_value = arr[top];
        top--;
        return popped_value;
    }

    // Return the top element of the stack
    int peek() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }

        return arr[top];
    }

    // Check if the stack is empty
    bool is_empty() {
        return top == -1;
    }

    // Print the elements of the stack
    void print() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.print(); // Should print: "Stack: 1 2 3"

    cout << "Popped element: " << s.pop() << endl; // Should print: "Popped element: 3"
    s.print();

    cout << "Top element: " << s.peek() << endl; // Should print: "Top element: 2"

    s.print(); // Should print: "Stack: 1 2"

    return 0;
}
