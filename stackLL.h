template<typename T>
class stack;

template<typename T>
class Node{
    T data;
    Node<T> *next;
    Node(T d){
        data = d;
    }
};

template<typename T>
class Stack{
    public:
    Node<T> *head;
    Stack(){
        head = NULL;
    }

    void push(T data){ // Insertion at head
        Node<T> * n = new Node<T>(data);
        n->next = head;
        head = n;
    }

    bool empty(){
        return head==NULL;
    }

    T top(){
        return head->data;
    }

    void pop(){
		if(head!=NULL){
			Node<T> * temp = head;
			head = head->next;
			delete temp;
		}

	}
    void display(){
        while(!s.empty){
            cout<<s.top();
            s.pop();
        }
    }
};