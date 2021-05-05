#include "queue.h"
#include <stdlib.h>

Node *nodeCreate() {
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	if(!tmp) {
		return NULL;
	}
	tmp->next = NULL;
	return tmp;
}

Queue *queueInit() {
	Queue *tmp;
	tmp = (Queue*)malloc(sizeof(Queue));
	if(!tmp) {
		printf("do not have enough memory for creating new Queue\n");
		return NULL;
	}
	tmp->count = 0;
	tmp->front = NULL;
	tmp->rear = NULL;
	return tmp;
}

bool isEmpty(Queue* q) {
	return q->rear == NULL;
}

void enqueue(Queue *q, Item val) {
	Node *new_node = nodeCreate();
	if(!new_node) {
		printf("do not have enough memory for creating new Node\n");
		exit(1);
	}
	new_node->data = val;
	new_node->next = NULL;
	if(!isEmpty(q)) {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->front = q->rear = new_node;
	q->count++;
}

Item dequeue(Queue *q) {
	Node *tmp_node;
	Item dequeue_data;
	dequeue_data = q->front->data;
	tmp_node = q->front;
	q->front = q->front->next;
	q->count--;
	free(tmp_node);
	return dequeue_data;
}

void queueDisplay(Queue *q) {
	Node *tmp = q->front;
	while(!tmp) {
		printf("%d -> ", tmp->data);
		tmp = tmp->next;
	}
}

void queueDestroy(Queue *q) {
	while(!isEmpty(q)) {
		dequeue(q);
	}
	free(q);
}
