#include<iostream>
using namespace std;

class node{

    public:
        int data;
        node*next;
    node(int d){
        this->data = d;
        this->next = NULL;
    }    

    ~node(){
        int value=this->data;
        if (this->next !=NULL){
            delete next;
        }
        this->next = NULL;
        cout << "deleted node is: " << value<<endl;
    }
};

void insertEnd(node* &tail,int d){
    node *newNode = new node(d);
    tail->next = newNode;
    tail = newNode;
}
void print(node* &head){
    node *temp = head;
    while(temp!=NULL){
        cout << temp->data<<endl;
        temp = temp->next;
    }
}

void deleteNode(node* &head,node*&tail,int position){

    //deleting start node
    if(position==1){
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else{
        //deleting middle and last node
        node *current = head;
        node *previous = NULL;
        int cnt = 1;
        while(cnt<position){
            previous = current;
            current = current->next;
            cnt++;
        }
        if(current->next==NULL){
            tail = previous;
        }

        previous->next = current->next;
        current->next = NULL;
        delete current;

        
    }
}

int main(){
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertEnd(tail, 12);
    insertEnd(tail, 15);
    deleteNode(head,tail, 3);
    print(head);
    cout << "head: " << head->data<<endl;
    cout << "tail: " << tail->data;

    return 0;
}