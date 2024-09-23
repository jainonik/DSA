#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(node*&tail,int data){
    node *newNode = new node(data);
    tail->next = newNode;
    tail = newNode;
}
void print(node*&head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

//using recursive approach

void reverse(node*&head,node*curr,node*prev){

    if(curr==NULL){
        head = prev;
        return;
    }
    node *forward = curr->next;
    curr->next = prev;
    reverse(head, forward, curr);
 
    // using the iterator approach
    //   if(head==NULL||head->next==NULL){
    //       return head;
    //   }
    //   prev = NULL;
    //   curr = head;
    //   while(curr!=NULL){
    //       node *forward = curr->next;
    //       curr->next = prev;
    //       prev = curr;
    //       curr = forward;
    //   }
    //   head = prev;
    // //   print(head);
  
    
}


void reverseLinkedList(node*&head){
    node *prev = NULL;
    node *curr = head;
    reverse(head, curr, prev);
   
}


int main(){
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertAtEnd(tail, 20);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 40);
    cout << "Original List:" << endl;
    print(head);

    reverseLinkedList(head);

    cout << "Reversed List:" << endl;
    print(head);

    return 0;
}