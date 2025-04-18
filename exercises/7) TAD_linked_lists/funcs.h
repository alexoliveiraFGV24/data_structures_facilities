#ifndef FUNCS_H
#define FUNCS_H


#include <iostream>


namespace TAD_listas_encadeadas {

    // Questao 1
    struct nodeStack {
        int value;
        nodeStack *prev;
    };
    struct Stack {
        nodeStack *top;
        int maxSize;
        int size;
    };
    Stack* createStack(int maxSize);
    int pushStack(Stack *s, nodeStack *node);
    int popStack(Stack *s, nodeStack **node);
    int peekStack(Stack *s, nodeStack **node);
    int isEmptyStack(Stack *s);
    void destroyStack(Stack* s);

    // Questao 2
    struct nodeQueue {
        int value;
        nodeQueue *next;
    };
    struct Queue {
        nodeQueue *top;
        int maxSize;
        int size;
    };
    Queue* createQueue(int maxSize);
    int enqueueQueue(Queue *q, nodeQueue *node);
    int dequeueQueue(Queue *q, nodeQueue **node);
    int frontQueue(Queue *q, nodeQueue **node);
    int isEmptyQueue(Queue *q);
    void destroyQueue(Queue* q);

    // Questoes 3, 4, 5a, 6, 7
    struct nodeList {
        int value;
        nodeList *next;
    };
    struct List {
        nodeList *head;
        int size;
        int maxSize;
    };
    List* createList(int maxSize);
    int insertList(List *l, nodeList *node);
    int removeList(List *l, nodeList **node);
    void printList(List *l);
    List *intersectionList(List *l1, List *l2);
    List *unionList(List *l1, List *l2);
    int invertConsecutiveElements1(List *l, int index);
    void invertList(List *l);
    void destroyList(List* l);
    void deleteNode(nodeList* node);

    // Questao 5b, 8
    struct nodeListDouble {
        int value;
        nodeListDouble *next;
        nodeListDouble *prev;
    };
    struct ListDouble {
        nodeListDouble *head;
        nodeListDouble *tail;
        int size;
        int maxSize;
    };
    ListDouble* createListDouble(int maxSize);
    int insertListDouble(ListDouble *l, nodeListDouble *node);
    int removeListDouble(ListDouble *l, nodeListDouble **node);
    int invertConsecutiveElements2(ListDouble *l, int index);
    void printListDouble(ListDouble *l);
    void destroyListDouble(ListDouble *l);
    ListDouble* unionLists(ListDouble* l1, ListDouble* l2);
}


#endif
