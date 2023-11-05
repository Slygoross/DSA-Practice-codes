#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
    friend class List;
};

class CirculerList{
    public:
    Node* head;
    Node* tail;
    CirculerList(){
        head=NULL;
        tail=head;
    }

    void push_front(int data){
        if (head == NULL) {
            // if the list is empty, make the new node the head
            Node* n = new Node(data);
            n->next = head;
            head = n;
            tail = head;
            
        }
        else {
            // insert the new node at the front of the list
            Node* n = new Node(data);
            n->next = head;
        }
    }

    void push_back(int data){
        if(head==NULL){
            push_front(data);
            return;
        }
        Node* n = new Node(data);
        Node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
        n->next = head;
    }
    void display(){
        if (head == NULL) {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
        cout << temp->data << "->";
        temp = temp->next;
    }   while(temp != head);
    }
    
};

int main(){
    CirculerList l;
    l.push_front(0);
    l.display();
    l.push_back(1);
    l.display();
    return 0;
}