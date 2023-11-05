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

    void countAndSum(){
        if(head==NULL){
            cout<<"Empty List"<<endl;
        }
        else{
            int count=0, sum=0;
            Node* temp = head;
            while(temp!=NULL){
                count++;
                sum+=temp->data;
                temp=temp->next;
            }
            cout<<endl;
            cout<<"Count = "<<count<<endl;
            cout<<"Sum = "<<sum<<endl;
        }
    }

    void pop_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void remove(int pos){//wrong logic
        Node* temp = head;
        for(int i = 1; i < pos; i++){
                temp = temp->next;
            }
        temp->next = temp->next->next;
        temp->next = NULL;
        delete temp->next;
    }
};

int main(){
    list l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(2);
    l.push_back(3);
    l.display();
    cout<<endl;
    l.remove(2);
    l.display();
    return 0;
}