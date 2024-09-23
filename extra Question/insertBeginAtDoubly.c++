#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void print(Node*&head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
int length(Node*&head){
    Node *temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertBegin(Node *&head,int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
    cout << length(head) << endl;
    insertBegin(head, 20);
    insertBegin(head, 30);
    insertBegin(head, 40);
    print(head);

    return 0;
}