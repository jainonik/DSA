#include <stdio.h>
#include <stdlib.h>

int top1 = -1;
int top2 = -1;
int size = 10;
char stack1[10];
char stack2[10];

void push1(char ch){
    if(top1 == size - 1){
        printf("Overflow in stack1\n");
    }
    else{
        stack1[++top1] = ch;
    }
}

void push2(char ch){
    if(top2 == size - 1){
        printf("Overflow in stack2\n");
    }
    else{
        stack2[++top2] = ch;
    }
}

char pop1(){
    if(top1 == -1){
        printf("Underflow in stack1\n");
        // return '\0'; 
    }
    else{
        return stack1[top1--];
    }
}

void reverse(){
    while(top1 != -1) {
        push2(pop1());
    }
}

void printStack2(){
    for(int i = 0; i <= top2; i++){
        printf("%c ", stack2[i]);
    }
    printf("\n");
}

int main(){
    push1('A');
    push1('P');
    push1('O');
    push1('O');
    push1('R');
    push1('V');
    push1('A');

    reverse();
    printStack2();

    return 0;
}