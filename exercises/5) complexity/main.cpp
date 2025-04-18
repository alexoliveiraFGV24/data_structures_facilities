#include "funcs.h"


using namespace complexidade;


int main() {

    // Questao 4
    int arr[50] = {3, -2, 5, -1, 6, -3, 7, -5, 2, 8, 
        -10, 15, -7, 4, -3, 9, -6, 11, -8, 12, 
        -1, 14, -2, 13, -9, 16, -4, 17, -12, 18, 
        -11, 19, -14, 20, -13, 21, -15, 22, -16, 23, 
        -18, 24, -17, 25, -19, 26, -20, 27, -21, 28};
    int* ptr = arr;

    clock_t t1;
    t1 = clock();
    subseq_contigua_n_3(ptr, 9); 
    t1 = clock() - t1;
    std::cout << "Tempo algoritmo O(n^3): " << ((float)t1)/CLOCKS_PER_SEC << " segundos" << std::endl;

    clock_t t2;
    t2 = clock();
    subseq_contigua_n_2(ptr, 9);
    t2 = clock() - t2;
    std::cout << "Tempo algoritmo O(n^2): " << ((float)t2)/CLOCKS_PER_SEC << " segundos" << std::endl;

    clock_t t3;
    t3 = clock();
    subseq_contigua_n(ptr, 9);
    t3 = clock() - t3;
    std::cout << "Tempo algoritmo O(n): " << ((float)t3)/CLOCKS_PER_SEC << " segundos" << std::endl;

    return 0;
}
