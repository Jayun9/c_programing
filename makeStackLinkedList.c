#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 999999

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Stack{
    Node *top;
} Stack;

void push(Stack *stack, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack* stack){
    if (stack->top == NULL){
        printf("스택 언더플로우가 발생했습니다.");
        return -INF;
    }
    Node* node = stack->top;
    int data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

void show(Stack* stack){
    Node *cur = stack->top;
    printf("------------스택의 최상단--------------\n");
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    printf("------------스택의 최하단--------------\n");
}

void freeAll(Stack* stack){
    Node *cur = stack->top;
    while (cur!=NULL){
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void){
    Stack s;
    s.top = NULL;
    push(&s,7);
    push(&s,5);
    push(&s,4);
    pop(&s);
    push(&s,6);
    pop(&s);
    show(&s);
    freeAll(&s);
    return 0;
}