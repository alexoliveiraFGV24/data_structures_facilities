#include "funcs.h"


using namespace ordenacao;


int main () {

    int arr1[] = {1, 2, 4, 4, 4, 6, 7};
    int n1 = 7;
    std::cout << "Primeira ocorrencia de 4: " << primeiraOcorrencia(arr1, n1, 4) << std::endl;
    std::cout << "Ultima ocorrencia de 4: " << ultimaOcorrencia(arr1, n1, 4) << std::endl;
    std::cout << "Contagem de [2, 6]: " << contarIntervalo(arr1, n1, 2, 6) << std::endl;

    int arr2[] = {5, 2, 9, 1, 3};
    insertionSort(arr2, 5);
    std::cout << "Insertion sort: ";
    for (int i = 0; i < 5; i++) std::cout << arr2[i] << " ";
    std::cout << std::endl;

    int arr3[] = {3, 1, 4, 2, 0};
    bubbleSort(arr3, 5);
    std::cout << "Bubble sort: ";
    for (int i = 0; i < 5; i++) std::cout << arr3[i] << " ";
    std::cout << std::endl;

    Tupla tuplas[] = {{3, 4}, {1, 2}, {3, 1}, {2, 2}};
    ordenarTuplas(tuplas, 4);
    std::cout << "Tuplas ordenadas: ";
    for (int i = 0; i < 4; i++) std::cout << "(" << tuplas[i].x << "," << tuplas[i].y << ") ";
    std::cout << std::endl;

    int arr5[] = {3, 1, 2, 6, 4, 5};
    insertionSortK(arr5, 6, 2);
    std::cout << "Insertion sort K=2: ";
    for (int i = 0; i < 6; i++) std::cout << arr5[i] << " ";
    std::cout << std::endl;

    return 0;
}
