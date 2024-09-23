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

void insert_end(node*&tail,int data){
    node *newNode = new node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(node*&head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

node* Kreverse(node*&head,int k){


    if(head==NULL){
        return NULL;
    }
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int cnt = 0;
    while(curr != NULL && cnt<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next!=NULL){
        head->next = Kreverse(next, k);
    }

    return prev;
}


int main(){
   node *node1 = new node(2);
    node *head = node1;
    node *tail = node1;
    int k = 3;
    insert_end(tail, 3);
    insert_end(tail, 4);
    insert_end(tail, 5);
    insert_end(tail, 6);
    cout << "Original List: " ;
    print(head);

    head=Kreverse(head,k);

    cout << "Reversed List: " ;
    print(head);

    return 0;
}