#include <iostream>
#include <string>

//Exercicio 1
struct Aluno {
    std::string nome;
    float nota;
};

//Exercicio 2
void preencheArray(int tamanho) {
    int* arr = new int[tamanho];
    for ( int i = 0; i < tamanho; i++ ){
        arr[i] = i+1;
        std::cout << arr[i] << " ";
    } 
    delete[] arr;
}

//Exercicio 3
enum Cargo {
    Estagiario, Junior, Pleno, Senior
};
struct Funcionario {
    std::string nome;
    Cargo cargo;
};


int main() {

    //Exercicio 1
    Aluno* aluno = new Aluno{"Joao", 2.5};
    std::cout << "O aluno " << aluno->nome << " tirou " << aluno->nota << " na prova de Algebra Linear." << std::endl;
    delete aluno;

    //Exercicio 2
    int tamanho;
    std::cout << "Digite o tamanho do array: " << std::endl;
    std::cin >> tamanho;
    preencheArray(tamanho);

    //Exercicio 3
    Funcionario* funcionarios = new Funcionario[2];
    funcionarios[0] = {"Joao", Pleno};
    funcionarios[1] = {"Alex", Senior};
    for (int i = 0; i < 2; i++) {
        std::cout << "Nome: " << funcionarios[i].nome << ", Cargo: " << funcionarios[i].cargo << std::endl;
    }    
    delete[] funcionarios;
    
    return 0;
}
