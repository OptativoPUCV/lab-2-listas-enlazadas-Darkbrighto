#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* L = (List *) malloc(sizeof(List));
    L->head=NULL;
    L->tail=NULL;
    L->current=NULL;
    return L;
}

void * firstList(List * list) {
    list->current = list->head;
    if (list->current) return list->current->data;
    return NULL;
}

void * nextList(List * list) {
    if (list->current != NULL )
        list->current = list->current->next;
    if (list->current != NULL)
        return list->current->data;
    return NULL;
}

void * lastList(List * list) {
    Node* aux = list->head;
    while ( aux->next != NULL )
    {
        aux = aux->next;
        list->current = aux;
    }
    return list->current->data;
}

void * prevList(List * list) {
    if (list->current != NULL )
        list->current = list->current->prev;
    if (list->current != NULL)
        return list->current->data;
    return NULL;
}

void pushFront(List * list, void * data) {
    Node* NewNode = (Node*) malloc(sizeof(Node));
    if (NewNode == NULL) {
        return; 
    }
    NewNode->data = data;
    NewNode->prev = NULL;
    NewNode->next = list->head;

    if (list->head) {
        list->head->prev = NewNode;
    } else {
        list->tail = NewNode;
    }
    list->head = NewNode;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node* NewNode = (Node*) malloc(sizeof(Node));
    if (NewNode == NULL) {
        return; 
    }
    NewNode->data = data;
    NewNode->prev = list->current;
    NewNode->next = NULL;


    if (list->current->next) {
        Node* aux = list->current->next;
        list->current->next = NewNode;
        aux->prev = NewNode;
        NewNode->next = aux;
    }

    list->tail = NewNode;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}