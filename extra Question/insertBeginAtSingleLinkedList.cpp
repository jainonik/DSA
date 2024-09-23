#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insertNode(Node*&head,int d){
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;

    
}

void print(Node*&head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    insertNode(head, 12);
  
    insertNode(head, 15);
    print(head);

    delete node1;

    return 0;
}