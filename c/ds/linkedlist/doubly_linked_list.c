#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Node {
    Item data;
    struct Node *next, *prev;
} Node;

typedef Node *List;

Node *createNewNode(Item);
List listInit();
bool isEmpty(List);
int getLength(List);
void insertNth(List *, Item, int);
void insertBegin(List *, Item);
void insertLast(List *, Item);
Item deleteNth(List *, int);
Item deleteLast(List *);
Item deleteBegin(List *);
void listDisplay(List);
void deleteList(List *);

Node *createNewNode(Item val) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (!tmp) {
        /* printf("out of memory"); */
        return NULL;
    }
    tmp->data = val;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

List listInit() {
    List tmp = NULL;
    return tmp;
}

bool isEmpty(List l) { return l == NULL ? true : false; }

int getLength(List l) {
    if (isEmpty(l)) {
        return 0;
    }
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->next;
    }
    return count;
}

void insertNth(List *l, Item val, int index) {
    Node *new_node = createNewNode(val);
    List tmp       = *l;
    int len;
    if (!new_node) {
        printf("out of memory");
        exit(1);
    }

    if (isEmpty(*l)) {
        new_node->next = NULL;
        new_node->prev = NULL;
        *l             = new_node;
        printf("new node is inserted\n");
        return;
    }
    len = getLength(*l);
    if (index < 0 || index >= len) {
        printf("index error");
        exit(1);

    } else if (index == 0) {
        new_node->next = tmp;
        new_node->prev = NULL;
        tmp->prev      = new_node;
        *l             = new_node;
        printf("new node is inserted\n");
        return;

    } else if (index == len - 1) {
        for (int i = len - 1; i > 0; i--) {
            tmp = tmp->next;
        }
        tmp->next      = new_node;
        new_node->prev = tmp;
    } else {
        for (int i = 1; i < index - 1; i++) {
            tmp = tmp->next; // move to index-1 th element
        }
        new_node->next  = tmp->next;
        tmp->next->prev = new_node;
        new_node->prev  = tmp;
        tmp->next       = new_node;
        printf("new node is inserted\n");
        return;
    }
}

void insertBegin(List *l, Item val) { insertNth(l, val, 0); }

void insertLast(List *l, Item val) { insertNth(l, val, getLength(*l) - 1); }

Item deleteNth(List *l, int index) {
    List tmp = *l;
    Node *deleted_node;
    Item data_deleted;
    int len;
    if (isEmpty(*l)) {
        printf("list is empty, cannot delete.");
        exit(1);
    }
    len = getLength(*l);
    if (!(0 < index < len)) {
        printf("index error");
        exit(1);
    } else if (index == 0) {
        data_deleted    = tmp->data;
        *l              = tmp->next;
        tmp->next->prev = NULL;
        free(tmp);
        return data_deleted;
    } else if (index == len - 1) {
        for (int i = len - 1; i > 0; i--) {
            tmp = tmp->next; // move to the last element
        }
        data_deleted    = tmp->data;
        tmp->prev->next = NULL;
        tmp->prev       = NULL;
        free(tmp);
        return data_deleted;
    } else {
        /* move to element indexth */
        for (int i = index - 1; i > 1; i--) {
            tmp = tmp->next;
        }
        deleted_node             = tmp->next;
        data_deleted             = deleted_node->data;
        tmp->next                = deleted_node->next;
        deleted_node->next->prev = tmp;
        free(deleted_node);
        return data_deleted;
    }
}

Item deleteLast(List *l) { return deleteNth(l, getLength(*l) - 1); }

Item deleteBegin(List *l) { return deleteNth(l, 0); }

void listDisplay(List l) {
    List tmp = l;
    if (isEmpty(l)) {
        printf("list is empty");
    }
    while (tmp != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void deleteList(List *l) {
    if (isEmpty(*l)) {
        printf("list is empty");
        exit(1);
    }
    Node *tmp_node;
    while (*l != NULL) {
        tmp_node = *l;
        *l       = (*l)->next;
        free(tmp_node);
    }
}

int main() {
    List l;
    l = listInit();
    for (int i = 0; i < 10; i++) {
        insertBegin(&l, i);
    }

    printf("\n");
    listDisplay(l);
    printf("delete 3th element\n");
    printf("%d\n", deleteNth(&l, 3));
    listDisplay(l);
    printf("length: %d\n", getLength(l));
    printf("deleteBegin: %d\n", deleteBegin(&l));
    printf("deleteLast: %d\n", deleteLast(&l));
    printf("length: %d\n", getLength(l));
    listDisplay(l);
    deleteList(&l);
    return 0;
}
