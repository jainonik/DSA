#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        ~Node(){
        int value=this->data;
        if (this->next !=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "deleted node is: " << value<<endl;
    }
};

void print(Node *&head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
    
}
void insertEnd(Node*&tail,int data){
    Node *newNode = new Node(data);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}
void insertBegin(Node *&head,int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void deleteNode(Node*&head,Node*&tail,int position){
    if(position==1){
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
        }
    else{
        Node* previous=NULL;
        Node* current = head;
        int cnt = 1;
        while(cnt<position){
            previous = current;
            current = current->next;
            cnt++;
        }
        if(current->next==NULL){
            tail = current->prev;
        }

        previous->next = current->next;
        current->prev = NULL;
        current->next = NULL;
        delete current;
        }

}


int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertEnd(tail, 20);
    insertEnd(tail, 30);
    insertEnd(tail, 40);
    deleteNode(head, tail, 4);
    print(head);
    cout << "head: " << head->data<<endl;
    cout << "tail: " << tail->data;


    return 0;
}