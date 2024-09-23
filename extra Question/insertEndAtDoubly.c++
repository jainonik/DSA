#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
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

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertEnd(tail, 20);
    insertEnd(tail, 30);
    insertEnd(tail, 40);

    print(head);

    return 0;
}