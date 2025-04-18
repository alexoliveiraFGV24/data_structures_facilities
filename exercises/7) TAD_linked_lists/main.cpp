#include <iostream>
#include "funcs.h"


using namespace TAD_listas_encadeadas;


int main () {

    // Questao 1
    Stack *s = createStack(5);
    nodeStack *node1 = new nodeStack{1};
    nodeStack *node2 = new nodeStack{2};
    nodeStack *node3 = new nodeStack{3};
    nodeStack *node4 = new nodeStack{4};
    pushStack(s, node1);
    pushStack(s, node2);
    pushStack(s, node3);
    pushStack(s, node4);
    nodeStack *topNode;
    peekStack(s, &topNode);
    nodeStack *poppedNode;
    popStack(s, &poppedNode);
    popStack(s, &poppedNode);
    peekStack(s, &topNode);
    destroyStack(s);

    // Questao 2
    Queue *q = createQueue(5);
    nodeQueue *node11 = new nodeQueue{1};
    nodeQueue *node21 = new nodeQueue{2};
    nodeQueue *node31 = new nodeQueue{3};
    nodeQueue *node41 = new nodeQueue{4};
    enqueueQueue(q, node11);
    enqueueQueue(q, node21);
    enqueueQueue(q, node31);
    enqueueQueue(q, node41);
    nodeQueue *frontNode;
    frontQueue(q, &frontNode);
    nodeQueue *dequeuedNode;
    dequeueQueue(q, &dequeuedNode);
    dequeueQueue(q, &dequeuedNode);
    frontQueue(q, &frontNode);
    destroyQueue(q);

    // Questoes 3 4
    List *l1 = createList(5);
    nodeList *node12 = new nodeList{5};
    nodeList *node22 = new nodeList{6};
    nodeList *node32 = new nodeList{8};
    nodeList *node42 = new nodeList{9};
    insertList(l1, node12);
    insertList(l1, node22);
    insertList(l1, node32);
    insertList(l1, node42);
    List *l2 = createList(4);
    nodeList *node13 = new nodeList{5};
    nodeList *node23 = new nodeList{9};
    nodeList *node33 = new nodeList{10};
    insertList(l2, node13);
    insertList(l2, node23);
    insertList(l2, node33);
    List *l3 = intersectionList(l1, l2);
    List *l4 = unionList(l1, l2);
    std::cout << "Intersection: ";
    printList(l3);
    std::cout << "Union: ";
    printList(l4);
    destroyList(l2);
    destroyList(l3);
    destroyList(l4);

    // Questao 5
    printList(l1);
    invertConsecutiveElements1(l1, 0);
    printList(l1);
    ListDouble *l5 = createListDouble(5);
    insertListDouble(l5, new nodeListDouble{1});
    insertListDouble(l5, new nodeListDouble{2});
    insertListDouble(l5, new nodeListDouble{3});
    insertListDouble(l5, new nodeListDouble{4});
    printListDouble(l5);
    invertConsecutiveElements2(l5, 2);
    printListDouble(l5);
    destroyList(l1);
    destroyListDouble(l5);

    // Questao 6
    List *l6 = createList(5);
    nodeList *node14 = new nodeList{1};
    nodeList *node24 = new nodeList{2};
    nodeList *node34 = new nodeList{3};
    nodeList *node44 = new nodeList{4};
    insertList(l6, node14);
    insertList(l6, node24);
    insertList(l6, node34);
    insertList(l6, node44);
    printList(l6);
    invertList(l6);
    printList(l6);
    destroyList(l6);

    // Questao 7


    // Questao 8
    ListDouble *l7 = createListDouble(5);
    nodeListDouble *node15 = new nodeListDouble{1};
    nodeListDouble *node25 = new nodeListDouble{2};
    nodeListDouble *node35 = new nodeListDouble{3};
    nodeListDouble *node45 = new nodeListDouble{4};
    insertListDouble(l7, node15);
    insertListDouble(l7, node25);
    insertListDouble(l7, node35);
    insertListDouble(l7, node45);
    printListDouble(l7);
    ListDouble *l8 = createListDouble(5);
    nodeListDouble *node16 = new nodeListDouble{8};
    nodeListDouble *node26 = new nodeListDouble{23};
    nodeListDouble *node36 = new nodeListDouble{9};
    nodeListDouble *node46 = new nodeListDouble{0};
    insertListDouble(l8, node16);
    insertListDouble(l8, node26);
    insertListDouble(l8, node36);
    insertListDouble(l8, node46);
    printListDouble(l8);
    ListDouble *l9 = unionLists(l7, l8);
    printListDouble(l9);


    return 0;
}
