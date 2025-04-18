#include "funcs.h"


namespace ordenacao {

    
    // Questao 1
    int primeiraOcorrencia(int arr[], int n, int x) {
        if (n == 0) return -1;
        int esquerda = 0, direita = n - 1, resultado = -1;
        while (esquerda <= direita) {
            int meio = (esquerda + direita) / 2;
            if (arr[meio] == x) {
                resultado = meio;
                direita = meio - 1;
            } else if (arr[meio] < x) {
                esquerda = meio + 1;
            } else {
                direita = meio - 1;
            }
        }
        return resultado;
    }
    int ultimaOcorrencia(int arr[], int n, int x) {
        int esquerda = 0, direita = n - 1, resultado = -1;
        while (esquerda <= direita) {
            int meio = (esquerda + direita) / 2;
            if (arr[meio] == x) {
                resultado = meio;
                esquerda = meio + 1;
            } else if (arr[meio] < x) {
                esquerda = meio + 1;
            } else {
                direita = meio - 1;
            }
        }
        return resultado;
    }
    int contarIntervalo(int arr[], int n, int x, int y) {
        int inicio = primeiraOcorrencia(arr, n, x);
        int fim = ultimaOcorrencia(arr, n, y);
        if (inicio == -1 || fim == -1 || inicio > fim) return 0;
        return fim - inicio + 1;
    }


    // Questao 2
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int chave = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > chave) {
                arr[j + 1] = arr[j];
                j -= 1;
            }
            arr[j + 1] = chave;
        }
    }

    // Questao 3
    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }
    void bubbleSortList(List* l) {
        if (!l || !l->head) return;
        bool trocou;
        do {
            trocou = false;
            nodeList* atual = l->head;
            while (atual && atual->next) {
                if (atual->value > atual->next->value) {
                    int tmp = atual->value;
                    atual->value = atual->next->value;
                    atual->next->value = tmp;
                    trocou = true;
                }
                atual = atual->next;
            }
        } while (trocou);
    }

    // Questao 4
    void ordenarTuplas(Tupla arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].x > arr[j + 1].x || (arr[j].x == arr[j + 1].x && arr[j].y > arr[j + 1].y)) {
                    Tupla tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }

    // Questao 5
    void insertionSortK(int arr[], int n, int k) {
        for (int i = 1; i < n; i++) {
            int chave = arr[i];
            int limite = 0;
            int j = i - 1;
            if  (j - k >= 0) {
                limite = j - k;
            }
            while (j >= limite && arr[j] > chave) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = chave;
        }
    }
}
