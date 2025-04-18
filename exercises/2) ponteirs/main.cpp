#include <iostream>

//Exercicio 1
void passagemValor(int a) {
    a = 100;
    std::cout << "Modifica a copia do numero." <<"\nValor da copia: " << a << std::endl;
}
void passagemReferencia(int& a) {
    a = 200;
    std::cout << "Modifica a referencia do numero.\nLogo, modifica o valor original" <<"\nValor novo: " << a << std::endl;
}
void passagemPonteiro(int* a) {
    *a = 300;
    std::cout << "Modifica o valor que o ponteiro aponta." <<"\nValor do novo apontamento: " << *a << std::endl;
}

//Exercicio 2
void trocaNumero(int* ptr_1, int* ptr_2) {
    int a;
    a = *ptr_1;
    *ptr_1 = *ptr_2;
    *ptr_2 = a;
    std::cout << "Valores depois da troca:" << std::endl;
    std::cout << "Valor 1: " << *ptr_1 << "\nValor 2: " << *ptr_2 << std::endl;
}

//Exercicio 3
void inverteArray(int tamanho, int* arr_1) {
    std::cout << "\nArray invertido:" << std::endl;
    for ( int i = tamanho-1; i >=0; i-- ){
        std::cout << arr_1[i] << " ";
    }
    std::cout << std::endl;
}

//Exercicio 4
void somaMatriz(int linhas, int colunas, int** matriz_1, int** matriz_2) {
    // Criando a matriz soma dinamicamente
    int** soma = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        soma[i] = new int[colunas]; // Aloca espaço para cada linha
    }

    // Somando os elementos das matrizes
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            soma[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
    }

    // Exibindo a matriz soma
    std::cout << "\nMatriz Soma:\n";
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cout << soma[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Liberando memória alocada
    for (int i = 0; i < linhas; i++) {
        delete[] soma[i];
    }
    delete[] soma;
}



int main() {

    //Exercicio 1
    int a = 10;
    int b = 20;
    int c = 30;
    int* ptr_c = &c;
    passagemValor(a);
    std::cout << "Valor original: " << a << "\n" << std::endl;
    passagemReferencia(b);
    std::cout << "Valor original: " << b << "\n" << std::endl;
    passagemPonteiro(ptr_c);
    std::cout << "Valor apontado original: " << *ptr_c << "\n" << std::endl;

    //Exercicio 2
    int num_1, num_2;
    std::cout << "Digite dois inteiros: " << std::endl;
    std::cin >> num_1 >> num_2;
    int* ptr_1 = &num_1;
    int* ptr_2 = &num_2;
    std::cout << "Valores antes da troca:" << std::endl;
    std::cout << "Valor 1: " << *ptr_1 << "\nValor 2: " << *ptr_2 << std::endl;
    trocaNumero(ptr_1, ptr_2);

    //Exercicio 3
    int tamanho;
    std::cout << "Digite o tamanho do array: " << std::endl;
    std::cin >> tamanho;
    int arr_1[tamanho];
    std::cout << "Digite o array: " << std::endl;
    for ( int i = 0; i < tamanho; i++ ){
        std::cin >> arr_1[i];
    }
    int* ptr_arr_1 = arr_1;
    std::cout << "Array antes: " << std::endl;
    for ( int i = 0; i < tamanho; i++ ){
        std::cout << arr_1[i] << " ";
    }
    inverteArray(tamanho, ptr_arr_1);

    //Exercicio 4
    int m, n;
    std::cout << "Digite o numero de linhas e colunas da matriz: ";
    std::cin >> m >> n;
    int** matriz_1 = new int*[m];
    int** matriz_2 = new int*[m];
    for (int i = 0; i < m; i++) {
        matriz_1[i] = new int[n];
        matriz_2[i] = new int[n];
    }
    std::cout << "Digite os elementos da primeira matriz (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz_1[i][j];
        }
    }
    std::cout << "Digite os elementos da segunda matriz (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz_2[i][j];
        }
    }
    somaMatriz(m, n, matriz_1, matriz_2);
    for (int i = 0; i < m; i++) {
        delete[] matriz_1[i];
        delete[] matriz_2[i];
    }
    delete[] matriz_1;
    delete[] matriz_2;
    
    return 0;
}
