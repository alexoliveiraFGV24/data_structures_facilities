#include "funcs.h"


namespace TADPilhaFilaLista {

    // Questao 7
    Deque *createDeque(int maxSize) {
        Deque *d = new Deque;
        d->data = new int[maxSize];
        d->maxSize = maxSize;
        d->front = 0;
        d->back = -1;
        d->size = 0;
        return d;
    }
    int pushFront(Deque *d, int value) {
        if (d->size == d->maxSize) {
            return 0;
        }
        d->front = (d->front - 1 + d->maxSize) % d->maxSize;
        d->data[d->front] = value;
        d->size += 1;
        return 1;
    }
    int pushBack(Deque *d, int value) {
        if (d->size == d->maxSize) {
            return 0;
        }
        d->back = (d->back + 1) % d->maxSize;
        d->data[d->back] = value;
        d->size += 1;
        return 1;
    }
    int popFront(Deque *d, int *value) {
        if (d->size == 0) {
            return 0;
        }
        *value = d->data[d->front];
        d->front = (d->front + 1) % d->maxSize;
        d->size -= 1;
        return 1;
    }
    int popBack(Deque *d, int *value) {
        if (d->size == 0) {
            return 0;
        }
        *value = d->data[d->back];
        d->back = (d->back - 1 + d->maxSize) % d->maxSize;
        d->size -= 1;
        return 1;
    }
    void printDeque(Deque *d) {
        int i = d->front;
        for (int count = 0; count < d->size; ++count) {
            std::cout << d->data[i] << " ";
            i = (i + 1) % d->maxSize;
        }
        std::cout << "\n";
    }
    void destroyDeque(Deque* d) {
        delete[] d->data;
        delete d;
    }


    // Questao 9
    Stack* createStack(int maxSize) {
        Stack * s = new Stack();
        s->data = new int[maxSize];
        s->maxSize = maxSize;
        s->top = -1;
        s->size = 0;
        s->minValue = s->minValuePrev = 0;
        return s;
    }
    int pushStack(Stack *s, int value) {
        if (s->top == s->maxSize) {
            return 0;
        }
        if (s->top == -1) {
            s->minValue = value;
            s->minValuePrev = value;
        } else if (value < s->minValue) {
            s->minValuePrev = s->minValue;
            s->minValue = value;
        }
        s->top += 1;
        s->data[s->top] = value;
        s->size += 1;
        return 1;
    }
    int popStack(Stack *s, int *value) {
        if (s->top == -1) {
            return 0;
        }
        if (s->data[s->top] == s->minValue) {
            s->minValue = s->minValuePrev;
        }
        *value = s->data[s->top];
        s->data[s->top] = s->data[s->top - 1];
        s->top -= 1;
        s->size -= 1;
        return 1;
    }
    int getMinValueStack1(Stack *s){
        if (s->top == -1) {
            return 0;
        }
        int minValue = s->data[0];
        for (int i = 0; i <= s->top; i++) {
            if (s->data[i] < minValue) {
                minValue = s->data[i];
            }
        }
        return minValue;
    }
    int getMinValueStack2(Stack *s){
        return s->minValue;
    }
    void printStack(Stack *s) {
        for (int i = 0; i <= s->top; i++) {
            std::cout << s->data[i] << " ";
        }
        std::cout << "\n";
    }
    void destroyStack(Stack* s) {
        delete[] s->data;
        delete s;
    }

}
