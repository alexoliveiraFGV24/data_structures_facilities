#include "funcs.h"

namespace TAD_listas_encadeadas{

    // Questao 1
    Stack* createStack(int maxSize) {
        Stack * s = new Stack;
        s->top = nullptr;
        s->maxSize = maxSize;
        s->size = 0;
        return s;
    }
    int pushStack(Stack *s, nodeStack *node) {
        if (s->size == s->maxSize) {
            return 0;
        }
        node->prev = s->top;
        s->top = node;
        s->size += 1;
        return 1;
    }
    int popStack(Stack *s, nodeStack **node) {
        if (s->size == 0 || s->top == nullptr) {
            return 0;
        }
        nodeStack *temp = s->top;
        *node = temp;
        s->top = s->top->prev;
        delete temp;
        s->size -= 1;
        return 1;
    }
    int peekStack(Stack *s, nodeStack **node) {
        if (s->size == 0 || s->top == nullptr) {
            return 0;
        }
        *node = s->top;
        std::cout << "Top: " << (*node)->value << "\n";
        return 1;
    }
    int isEmptyStack(Stack *s) {
        return s->size == 0;
    }
    void destroyStack(Stack* s) {
        nodeStack *temp = s->top;
        while (temp != nullptr) {
            nodeStack *next = temp->prev;
            delete temp;
            temp = next;
        }
        delete s;
    }
    

    // Questao 2
    Queue* createQueue(int maxSize) {
        Queue * q = new Queue;
        q->top = nullptr;
        q->maxSize = maxSize;
        q->size = 0;
        return q;
    }
    int enqueueQueue(Queue *q, nodeQueue *node) {
        if (q->size == q->maxSize) {
            return 0;
        }
        if (q->top == nullptr) {
            q->top = node;
            node->next = nullptr;
        } else {
            nodeQueue *temp = q->top;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
            node->next = nullptr;
        }
        q->size += 1;
        return 1;
    }
    int dequeueQueue(Queue *q, nodeQueue **node) {
        if (q->size == 0 || q->top == nullptr) {
            return 0;
        }
        nodeQueue *temp = q->top;
        *node = temp;
        q->top = q->top->next;
        delete temp;
        q->size -= 1;
        return 1;
    }
    int frontQueue(Queue *q, nodeQueue **node) {
        if (q->size == 0 || q->top == nullptr) {
            return 0;
        }
        *node = q->top;
        std::cout << "Front: " << (*node)->value << "\n";
        return 1;
    }
    int isEmptyQueue(Queue *q) {
        return q->size == 0;
    }
    void destroyQueue(Queue* q) {
        nodeQueue *temp = q->top;
        while (temp != nullptr) {
            nodeQueue *next = temp->next;
            delete temp;
            temp = next;
        }
        delete q;
    }
    

    // Questoes 3, 4 ,5a, 6, 7
    List* createList(int maxSize) {
        List * l = new List;
        l->head = nullptr;
        l->maxSize = maxSize;
        l->size = 0;
        return l;
    }
    int insertList(List *l, nodeList *node) {
        if (l->size == l->maxSize) {
            return 0;
        }
        if (l->head == nullptr) {
            l->head = node;
            node->next = nullptr;
        } else {
            nodeList *temp = l->head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
            node->next = nullptr;
        }
        l->size += 1;
        return 1;
    }
    int removeList(List *l, nodeList **node) {
        if (l->size == 0 || l->head == nullptr) {
            return 0;
        }
        nodeList *temp = l->head;
        *node = temp;
        l->head = l->head->next;
        delete temp;
        l->size -= 1;
        return 1;
    }
    void destroyList(List* l) {
        nodeList *temp = l->head;
        while (temp != nullptr) {
            nodeList *next = temp->next;
            delete temp;
            temp = next;
        }
        delete l;
    }
    void printList(List *l) {
        nodeList *temp = l->head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    List *intersectionList(List *l1, List *l2) {
        List *l3 = createList(l1->maxSize + l2->maxSize);
        nodeList *temp1 = l1->head;
        while (temp1 != nullptr) {
            nodeList *temp2 = l2->head;
            while (temp2 != nullptr) {
                if (temp1->value == temp2->value) {
                    nodeList *newNode = new nodeList{temp1->value};
                    insertList(l3, newNode);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return l3;
    }
    List *unionList(List *l1, List *l2) {
        List *l3 = createList(l1->maxSize + l2->maxSize);
        nodeList *pivot1 = l1->head;
        while (pivot1 != nullptr) {
            nodeList *newNode = new nodeList{pivot1->value};
            insertList(l3, newNode);
            pivot1 = pivot1->next;
        }
        nodeList *pivot2 = l2->head;
        while (pivot2 != nullptr) {
            nodeList *newNode = new nodeList{pivot2->value};
            insertList(l3, newNode);
            pivot2 = pivot2->next;
        }
        nodeList *current = l3->head;
        while (current != nullptr) {
            nodeList *temp = current;
            while (temp->next != nullptr) {
                if (temp->next->value == current->value) {
                    nodeList *duplicate = temp->next;
                    temp->next = temp->next->next;
                    delete duplicate;
                    l3->size -= 1;
                } else {
                    temp = temp->next;
                }
            }
            current = current->next;
        }
        return l3;
    }
    int invertConsecutiveElements1(List *l, int index) {
        if (l == nullptr || l->head == nullptr || index < 0 || index >= l->size - 1) {
            return 0;
        }
        nodeList *prev = nullptr;
        nodeList *first = l->head;
        for (int i = 0; i < index; i++) {
            prev = first;
            first = first->next;
        }
        nodeList *second = first->next;
        if (second == nullptr) return 0;
        first->next = second->next;
        second->next = first;
        if (prev != nullptr) {
            prev->next = second;
        } else {
            l->head = second;
        }
        return 1;
    }
    void invertList(List *l) {
        if (l == nullptr || l->head == nullptr) return;
        nodeList *next = nullptr;
        nodeList *prev = nullptr;
        nodeList *curr = l->head;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l->head = prev;
    }
    void deleteNode(nodeList* node) {
        if (!node || !node->next) return;
    
        nodeList* temp = node->next;
        node->value = temp->value;
        node->next = temp->next;
        delete temp;
    }
    
    
    // Questao 5b, 8
    ListDouble* createListDouble(int maxSize) {
        ListDouble * l = new ListDouble;
        l->head = l->tail = nullptr;
        l->maxSize = maxSize;
        l->size = 0;
        return l;
    }
    int insertListDouble(ListDouble *l, nodeListDouble *node) {
        if (l->size == l->maxSize) {
            return 0;
        }
        if (l->head == nullptr) {
            l->head = l->tail = node;
            node->next = node->prev = nullptr;
        } else {
            l->tail->next = node;
            node->prev = l->tail;
            node->next = nullptr;
            l->tail = node;
        }
        l->size += 1;
        return 1;
    }
    int removeListDouble(ListDouble *l, nodeListDouble **node) {
        if (l->size == 0 || l->head == nullptr) {
            return 0;
        }
        nodeListDouble *temp = l->head;
        *node = temp;
        if (l->head == l->tail) {
            l->head = l->tail = nullptr;
        } else {
            l->head = l->head->next;
            l->head->prev = nullptr;
        }
        delete temp;
        l->size -= 1;
        return 1;
    }
    void destroyListDouble(ListDouble* l) {
        nodeListDouble *temp = l->head;
        while (temp != nullptr) {
            nodeListDouble *next = temp->next;
            delete temp;
            temp = next;
        }
        delete l;
    }
    void printListDouble(ListDouble *l) {
        nodeListDouble *temp = l->head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    int invertConsecutiveElements2(ListDouble *l, int index) {
        if (l == nullptr || l->head == nullptr || index < 0 || index >= l->size) {
            return 0;
        }
        nodeListDouble *first = l->head;
        for (int i = 1; i <= index; i++) {
            first = first->next;
        }
        nodeListDouble *second = first->next;
        if (second == nullptr) return 0;
        nodeListDouble *prev = first->prev;
        nodeListDouble *next = second->next;
        if (prev != nullptr) {
            prev->next = second;
        } else {
            l->head = second;
        }
        if (next != nullptr) {
            next->prev = first;
        } else {
            l->tail = first;
        }
        second->prev = prev;
        first->next = next;
        second->next = first;
        first->prev = second;
        return 1;
    }
    ListDouble* unionLists(ListDouble* l1, ListDouble* l2) {
        if (l1->head == nullptr) return l2;
        if (l2->head == nullptr) return l1;
    
        l1->tail->next = l2->head;
        l1->tail = l2->tail;
        l1->size += l2->size;
    
        destroyListDouble(l2);
        return l1;
    }
}
