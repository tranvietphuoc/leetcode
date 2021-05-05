#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef float Item;

typedef struct Node {
    Item data;
    struct Node* next;
} Node;

typedef Node* List;

Node *createNewNode(Item);
List listInit();
bool isEmpty(List);
int getLength(List);
Item deleteNth(List*, int);
void insertNth(List*, Item, int);
void listDisplay(List);
void insertBegin(List*, Item);
void insertLast(List*, Item);
void deleteList(List*);
void deleteBegin(List*);
void deleteLast(List*);
int searchItem(List, Item);


Node *createNewNode(Item val) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	if(!tmp) {
		return NULL;
	}
	tmp->data = val;
	tmp->next = NULL;
	return tmp;
}

List listInit() {
	List tmp = NULL;
	return tmp;

}


bool isEmpty(List l) {
    return l == NULL ? true : false;
}


int getLength(List l) {
    int count = 0;
    if(isEmpty(l)) {
        return count;
    }

    while(l != NULL) {
        count++;
        l = l->next;
    }
    return count;
}


void insertNth(List *l, Item val, int index) {
    List tmp_list;
    Node *new_node;
    int len;
    // create new node
    new_node = createNewNode(val);

	if(!new_node) {
		printf("out of memory");
		exit(1);
	}
    // check if List is empty
    if(isEmpty(*l)) {
        // then point list head to new node
        new_node->next = NULL;
        *l = new_node;
		return;
    }

    // if l is not empty
    tmp_list = *l;  // point to the first element
    len = getLength(*l);

    if(index < 0 || index > len) {
        printf("error! index out of range");
        exit(1);
    } else if(index == 0) {
        new_node->next = tmp_list;
        *l = new_node;
	}else if(index == len - 1) {
		for(int i = index; i > 0; i--) {
			tmp_list = tmp_list->next;  // move to the last element of list;
		}
		tmp_list->next = new_node;  // add new new_node to last element;
	} else {
		for(int i = 1; i < index - 1; i++){
			tmp_list = tmp_list->next;  // move to index - 1 element of list;
		}
        new_node->next = tmp_list->next;
        tmp_list->next = new_node;
    }
}


void insertBegin(List *l, Item val) {
    insertNth(l, val, 0);
}


void insertLast(List *l, Item val) {
    insertNth(l, val, getLength(*l) - 1);
}


Item deleteNth(List *l, int index) {
    Item data;
	Node *tmp_node;
    if(isEmpty(*l)) {
        printf("error! list is NULL");
        exit(1);
    }
    Node *tmp = *l;
    int len = getLength(*l);
    if(!(0 <= index < len)) {
        printf("error! index out of range");
        exit(1);
	} else if (index == 0) {
		*l = tmp->next;
		data = tmp->data;

		free(tmp);
		return data;
	} else {
        while(index - 1 > 0) {
            tmp = tmp->next;
            index--;
        }
		tmp_node = tmp->next;
        tmp->next = tmp_node->next;
        data = tmp_node->data;
        free(tmp_node);
        return data;
    }
}


void deleteBegin(List* l) {
	deleteNth(l, 0);
}

void deleteLast(List* l) {
	deleteNth(l, getLength(*l) -1);
}


int searchItem(List l, Item i) {
	int index = 0;
	while(l != NULL) {
		if(i == l->data) {
			return index;
		}
		index++;
		l = l->next;
	}
	return -1;
}

void listDisplay(List l){
    if(isEmpty(l)) {
        printf("list is empty");
    }
    while(l != NULL) {
        printf("%.f -> ", l->data);
        l = l->next;
    }
	printf("\n");
}


void deleteList(List *l) {
    Node *tmp;
    while(*l != NULL) {
        tmp = *l;
        *l = (*l)->next;
        free(tmp);
    }
}


int main(){
    List l;
    l = listInit();
    printf("Is empty: %d\n", isEmpty(l));
    printf("Length: %d\n", getLength(l));

    // add elements to list;
	for(int i = 0; i < 20; i++) {
		insertBegin(&l, i);
	}

	listDisplay(l);
	insertNth(&l, 111, 4);
	listDisplay(l);
	insertLast(&l, 12);
    listDisplay(l);
	printf("Deleted node at: %d, value: %.f\n",5, deleteNth(&l, 5));
	deleteBegin(&l);
	deleteLast(&l);
	printf("After deleted:\n");
	listDisplay(l);
	printf("search: %d", searchItem(l, 100));
	deleteList(&l);
    return 0;

}
