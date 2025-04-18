#ifndef FUNCS_H
#define FUNCS_H


#include <iostream>


namespace ordenacao {
    
    // Questao 1
    int primeiraOcorrencia(int arr[], int n, int x);
    int ultimaOcorrencia(int arr[], int n, int x);
    int contarIntervalo(int arr[], int n, int x, int y);
    

    // Questao 2
    void insertionSort(int arr[], int n);


    // Questao 3
    void bubbleSort(int arr[], int n);
    struct nodeList {
        int value;
        nodeList *next;
    };
    struct List {
        nodeList *head;
        int size;
        int maxSize;
    };
    void bubbleSortList(List* l);
    

    // Questao 4
    struct Tupla {
        int x;
        int y;
    };
    void ordenarTuplas(Tupla arr[], int n);


    // Questao 5
    void insertionSortK(int arr[], int n, int k);


}


#endif