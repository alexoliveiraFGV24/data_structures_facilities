#ifndef FUNCS_H
#define FUNCS_H


#include <iostream>


namespace TADPilhaFilaLista {

    // Questao 7
    struct Deque {
        int *data;
        int maxSize;
        int size;
        int front;
        int back;
    };
    Deque *createDeque(int maxSize);
    int pushFront(Deque *d, int value);
    int pushBack(Deque *d, int value);
    int popFront(Deque *d, int *value);
    int popBack(Deque *d, int *value);
    void printDeque(Deque *d);
    void destroyDeque(Deque *d);

    // Questao 9
    struct Stack {
        int* data;
        int maxSize;
        int size;
        int top;
        int minValue;
        int minValuePrev;
    };
    Stack *createStack(int maxSize);
    int pushStack(Stack *s, int value);
    int popStack(Stack *s, int *value);
    int getMinValueStack1(Stack *s);
    int getMinValueStack2(Stack *s);
    void printStack(Stack *s);
    void destroyStack(Stack *s);
}

#endif