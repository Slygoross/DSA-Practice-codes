#include<iostream>
using namespace std;

class DoublyList;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }

    friend class DoublyList;
};

class DoublyList{
    public:
    Node* head;
    Node* tail;
    DoublyList(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int data){
        if(head==NULL){
            Node* n = new Node(data);
            head = tail = n;
        }
        else{
            Node* n = new Node(data);
            n -> next = head;
            head -> prev = n;
            head = n;
        }
    }

    void push_back(int data){
        if(head==NULL){
            Node* n = new Node(data);
            head = tail = n;
        }
        else{
            Node* n = new Node(data);
            tail->next = n;
            n->prev=tail;
            tail = n;
        }
    }

    void insert(int data, int position){
        if(position==0){
            push_front(data);
            return;
        }
        else{
            Node* temp = head;
            for(int jump = 1; jump <= position-1; jump++){
                temp = temp->next;
            }
            Node* n = new Node(data);
            n->next = temp->next;
            temp->next = n;
            n->prev = temp;
            n->next->prev=n;
        }
    }

    void pop_front(){
        if(head==NULL){
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            if(head!=NULL){
                head->prev = NULL;
            }
            delete temp;
        }
    }

    void pop_back(){
        if(head==NULL){
            return;
        }
        if (head->next == NULL) {
            delete head;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->prev->next = NULL;
            temp->prev=NULL;
            delete temp;
        }
    }

    void remove(int position){
        if(position == 1){
            pop_front();
            return;
        }
        Node* temp = head;
        int count = 1;
        while(temp!=NULL && count!=position){
            temp = temp->next;
            count++;
        }
        temp->prev->next = temp->next;
        if(temp->next!=NULL){
            temp->next->prev = temp->prev;
        }
        delete temp;


    }

    void display(){
        while(head!=NULL){
            cout<<head->data<<"->";
            head = head -> next;
        }
    }
};

int main(){
    DoublyList l;
    l.push_front(1);
    l.display();
    l.push_front(0);
    l.display();
    l.push_back(2);
    l.display();
    l.push_back(3);
    l.display();
    l.pop_back();
    l.display();
    l.pop_front();
    l.display();
    cout<<endl;
}