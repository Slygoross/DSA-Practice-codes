#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left = right = NULL;
        }

};

Node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    Node* n = new Node(d);
    n->left= buildTree();
    n->right= buildTree();
    return n;
}

void leverOrderprint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            //insert a new null for the next element
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return;
    }
}

int main(){
    Node* root = buildTree();
    leverOrderprint(root);
    return 0;
}