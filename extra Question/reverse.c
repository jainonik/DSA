#include<stdio.h>
#define max 6

typedef struct stack
{
    int arr[max];
    int top;

}stk;

void initStack(stk* s) {
    s->top = -1;
}

int isFull(stk*s){
    return s->top == max - 1;
}

int isEmpty(stk *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stk *s,int val){
    if(isFull(s)){
        printf("stack overflow\n");
        return;
    }
    else{
        s->arr[++(s->top)] = val;
    }
}

int pop(stk*s){
    if(isEmpty(s)){
        printf("stack underflow\n");
        return -1;
    }
    else{
        return s->arr[(s->top)--];
    }
}
void show(stk *s){
    if(isEmpty(s)){
        printf("stack is empty\n");
    }
    else{
        printf("stacks element is: \n");
        for (int i = 0; i <= s->top;i++){
            printf("%d  ", s->arr[i]);
        }
        printf("\n");
    }
}

void reverse(stk*s){
    stk temp;
    initStack(&temp);

    while(!isEmpty(s)){
        push(&temp, pop(s));
    }
    show(&temp);
}



int main(){
    stk s;
    initStack(&s);
    push(&s, 2);
    push(&s, 5);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);
    push(&s, 9);

    printf("original stack is: ");
    show(&s);
    reverse(&s);

    return 0;
}