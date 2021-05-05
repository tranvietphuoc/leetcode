#include "stack.h"
#include <stdlib.h>


Stack *stackInit() {
    Stack *s;
    s = (Stack*)malloc(sizeof(Stack));
    if(!s) {
        return NULL; // no memory
    }
    s->top = NULL;
	s->count = 0;
    return s;
}

void stackDestroy(Stack* s) {
    while(!stackIsEmpty(s)) {
        stackPop(s);
    }
    free(s);
}

int stackIsEmpty(const Stack *s) {
    return (s->top == NULL);
}

int stackIsFull() {
    printf("NO MEMORY! STACK IS FULL\n");
    return 1;
}

int stackPush(Stack *s, Item i) {
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    if(!temp) {
        stackIsFull();
        return 1;
    }
    temp->data = i;
    temp->next = s->top;
    s->top = temp;
	s->count++;
    return 0;
}

Item stackPop(Stack *s) {
    Item temp;
    Node* tempNode;
    tempNode = (Node*)malloc(sizeof(Node));
    if(!stackIsEmpty(s)) {
        tempNode = s->top;
        temp = tempNode->data;
        s->top = tempNode->next;
		s->count--;
        free(tempNode);
        return temp;
    }
    return (Item)(-1000);
}

void stackDisplay(Stack *s) {
    Node* tempNode;
    Item tempData;
    int counter=0;
    tempNode = (Node*)malloc(sizeof(Node));
    if(!stackIsEmpty(s)) {
        tempNode = s->top;
        do {
            tempData = tempNode->data;
            printf("%8.3f", tempData);
            counter++;
            tempNode = tempNode->next;
        } while(!(tempNode == NULL));
        printf("\n");
    }
    printf("\nStack is empty\n");
}
