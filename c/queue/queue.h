#include <stdbool.h>
#include <stdio.h>

typedef int Item;

typedef struct Node {
    Item data;
    Node *next;
} Node;

typedef struct Queue {
    int count;
    Node *front;
    Node *rear;
} Queue;

Node *nodeCreate();
Queue *queueInit();
bool isEmpty(Queue *);
void enqueue(Queue *, Item);
Item dequeue(Queue *);
void queueDisplay(Queue *);
void queueDestroy(Queue *);
