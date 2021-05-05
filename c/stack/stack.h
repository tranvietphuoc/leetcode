#include <stdio.h>

typedef float Item;

typedef struct Node {
    Item data;
    Node *next;  // point to next element
} Node;

typedef struct Stack {
	int count;
    Node *top;
} Stack;


// initialize stack
//
Stack *stackInit();

// destroy stack
void stackDestroy(Stack *s);

// check empty stack
int stackIsEmpty(const Stack *s);

// check stack full
int stackIsFull();

// display stack element
void stackDisplay(Stack* s);

// stack push
int stackPush(Stack* s, Item i);

// Stack pop
Item stackPop(Stack *s);
