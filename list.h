#include<iostream>
using namespace std;

class list;
class Node{
    int data;
    public:
    Node* next;
    Node(int d):data(d),next(NULL){}

    int getData(){
        return data;
    }

    friend class list;
};

class list{
    Node* head;
    Node* tail;

    public:
    list():head(NULL),tail(NULL){}

    Node* begin(){
        return head;
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
            head = tail = n;
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

        Node* temp = head;
        for(int jump = 1; jump <= position-1; jump++){
            temp  = temp->next;
        }

        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    void display(){
        if(head==NULL){
            cout<<"Empty List"<<endl;
        }
        else{
            Node* head = begin();
            while(head!=NULL){
            cout<<head->getData()<<"->";
            head = head->next;
            }
        }
    }
};