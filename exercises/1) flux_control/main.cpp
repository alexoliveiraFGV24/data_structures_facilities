#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>

//Exercicio 1
std::string classificaNumero(int numero){
    if ( typeid(numero) != typeid(int) )
        return "Precisa ser um numero";
    if ( numero > 0 ){
        return "O numero eh positivo";
    } else if ( numero == 0 ) {
        return "O numero eh nulo";
    } else {
        return "O numero eh negativo";
    }
}

//Exercicio 2
int somaArray(int tamanho, int arr[]){
    int soma = 0;
    for ( int i = 0; i < tamanho; i++ ){
        soma += arr[i];
    }
    return soma;
}

//Exercicio 3
bool ehPrimo(int numero) {
    if ( (typeid(numero) != typeid(int)) || (numero <= 0) || (numero == 1) ) {
        return false;
    }
    for ( int i = 2; i <= std::sqrt(numero); i++ ) {
        if ( numero % i == 0 ){
            return false;
        }
    }
    return true;
}

int main() {

    //Exercicio 1
    int numero;
    std::cout << "Digite um numero: " << std::endl;
    std::cin >> numero;
    std::cout << classificaNumero(numero) << std::endl;

    //Exercicio 2
    int tamanho;
    std::cout << "Digite o tamanho: " << std::endl;
    std::cin >> tamanho;
    int arr[tamanho];
    std::cout << "Digite o array: " << std::endl;
    for ( int i = 0; i < tamanho; i++ ){
        std::cin >> arr[i]; 
    }
    std::cout << "A soma foi: " << somaArray(tamanho, arr) << std::endl;

    //Exercicio 3
    int primo;
    std::cout << "Digite um numero inteiro: " << std::endl;
    std::cin >> primo;
    std::cout << "O numero eh primo: " << ehPrimo(primo) << std::endl;

    return 0;
}
