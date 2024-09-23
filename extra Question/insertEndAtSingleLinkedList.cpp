#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d){
        this->data = d;
        this->next = NULL;
    }

};

void insertEnd(node* &tail,int d){
    node *newNode = new node(d);
    tail->next = newNode;
    // tail = newNode;
    // also do this
    tail = tail->next;
}
void print(node*&head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main(){
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertEnd(tail, 12);
    insertEnd(tail, 15);
    print(head);

    return 0;
}