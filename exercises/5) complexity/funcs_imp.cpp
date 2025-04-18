#include "funcs.h"

namespace complexidade {
    
    // Questao 4
    // Algoritmo O(n^3) (forca bruta)
    void subseq_contigua_n_3(int *arr, int tamanho) {

        int max_soma = 0;
        int inicio = 0;
        int fim = 0;

        for (int i = 0; i < tamanho; i++) { 
            for (int j = i; j < tamanho; j++) { 
                int soma = 0;
                for (int k = i; k <= j; k++){ 
                    soma += arr[k];
                }
                if (soma > max_soma){ 
                    max_soma = soma;
                    inicio = i;
                    fim = j;
                }
            }
        }

        std::cout << "Algoritmo de forca bruta (percorrendo todas as subsequencias do array)" << std::endl;
        std::cout << "Maxima soma: " << max_soma << " (indices " << inicio << " a " << fim << ")" << std::endl;
    }


    // Algoritmo O(n^2) (soma acumulada)
    void subseq_contigua_n_2(int *arr, int tamanho) {

        int max_soma = 0;
        int inicio = 0; 
        int fim = 0; 

        for (int i = 0; i < tamanho; i++) { 
            int soma = 0;
            for (int j = i; j < tamanho; j++) { 
                soma += arr[j];
                if (soma > max_soma){ 
                    max_soma = soma;
                    inicio = i;
                    fim = j;
                }
            }
        }

        std::cout << "Algoritmo com soma acumulada (removemos o for da soma)" << std::endl;
        std::cout << "Maxima soma: " << max_soma << " (indices " << inicio << " a " << fim << ")" << std::endl;
    }


    // Algoritmo O(n) (Algoritmo de Kadane)
    void subseq_contigua_n(int *arr, int tamanho) {

        int max_soma = arr[0];  
        int max_atual = arr[0];  
        int inicio = 0; 
        int fim = 0;  
        int temp_inicio = 0; 

        for (int i = 1; i < tamanho; i++) {  
            if (arr[i] > max_atual + arr[i]){  
                max_atual = arr[i];
                temp_inicio = i;
            } else { 
                max_atual += arr[i];
            }
            if (max_atual > max_soma) {  
                max_soma = max_atual;
                inicio = temp_inicio;
                fim = i;
            }
        }

        std::cout << "Algoritmo de forca bruta (percorrendo todas as subsequencias do array)" << std::endl;
        std::cout << "Maxima soma: " << max_soma << " (indices " << inicio << " a " << fim << ")" << std::endl;
    }

}
