#include<iostream>
using namespace std;

class List;

class Node{
    public:
    int data;
    Node*  next;

    Node(int d){
        data = d;
        next = NULL;
    }

    friend class List;
};

class List{
    public:
    Node* head;
    Node* tail;
    List(){
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
            n->next = head;
            head = n;
        }
    }

    void push_back(int data){
        if(head==NULL){
            Node* n = new Node(data);
            head =  tail = n;
        }
        else{
            Node* n = new Node(data);
            tail->next = n;
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
            for(int jump = 1; jump <= position - 1; jump++){
                temp = temp -> next;
            }
            Node* n = new Node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }

    Node* reverse(Node* &head){
        Node* C = head;
        Node* P = NULL;
        Node* N;

        while(C!=NULL){
            C->next=P;
            N=C->next;
            P=C;
            C=N;
        }

        return P;
    }

    void display(){
        while(head!=NULL){
            cout<<head->data<<"->";
            head = head -> next;
        }
    }
};

int main(){
    List l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(2);
    l.push_back(3);
    l.display();
    l.display();
} 