#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int value;
    struct node_* next;
} node;

typedef struct list_ {
    node* head;
    node* tail;
} list;

node* createNode(int value) {
    node* n = (node*) malloc(sizeof(node));
    n->next = NULL;
    n->value = value;
    return n;
}

list* createList() {
    list* l = (list*) malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL; 
    return l;
}

int size(list* l) {
    int s = 0;
    for (node* n = l->head; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

void append(list* l, int value) {
    node* newNode = createNode(value);
    
    if (l->head == NULL) {
        l->head = newNode;
        l->tail = newNode; 
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

int main() {
    list* l = createList();

    append(l, 1);
    append(l, 2);
    append(l, 3);

    for (node* n = l->head; n != NULL; n = n->next) {
        printf("%d\n", n->value);
    }

    return 0;
}
