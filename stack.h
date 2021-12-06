// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a stack
typedef struct Stack {
    int x;
    int y;
    struct Stack* next;
} Stack;
 
Stack* allocate_stack(int data1, int data2) {
    Stack* stackNode = (struct Stack*)malloc(sizeof(Stack));
    stackNode->x = data1;
    stackNode->y = data2;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(Stack* root) {
    return !root;
}

void push(Stack** root, int data1, int data2) {
    Stack* stackNode = allocate_stack(data1, data2);
    stackNode->next = *root;
    *root = stackNode;
    printf("(%d, %d) pushed to stack\n", data1, data2);
}
 
void pop(Stack** root) {
    if (isEmpty(*root)) {
        printf("Empty\n");
    } else {
        Stack* temp = *root;
        *root = (*root)->next;
        printf("(%d, %d) popped from stack\n", temp->x, temp->y);
        free(temp);
    }
}
 
void peek(Stack* root) {
    if (isEmpty(root)) {
        printf("Empty\n");
    } else {
        int x, y;
        x = root->x;
        y = root->y;
        printf("Top of stack: (%d, %d)\n", x, y);
    }
}