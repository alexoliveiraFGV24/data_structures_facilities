#include "funcs.h"


using namespace TADPilhaFilaLista;


int main() {

    // Questao 7
    Deque *d = createDeque(5);
    pushBack(d, 1);
    pushBack(d, 2);
    pushFront(d, 3);
    pushFront(d, 4);
    printDeque(d);
    int value;
    popFront(d, &value);
    popBack(d, &value);
    printDeque(d);
    destroyDeque(d);

    // Questao 9
    Stack *s = createStack(5);
    pushStack(s, 5);
    pushStack(s, 3);
    pushStack(s, 0);
    pushStack(s, -2);
    pushStack(s, 4);
    printStack(s);
    std::cout << "Min value (method 1): " << getMinValueStack1(s) << "\n";
    std::cout << "Min value (method 2): " << getMinValueStack2(s) << "\n";
    int value1;
    popStack(s, &value1);
    popStack(s, &value1);
    printStack(s);
    std::cout << "Min value (method 1): " << getMinValueStack1(s) << "\n";
    std::cout << "Min value (method 2): " << getMinValueStack2(s) << "\n";
    destroyStack(s);

    return 0;
}
