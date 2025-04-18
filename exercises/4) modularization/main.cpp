#include <iostream>
#include "conversao.h"

int main(){
    double celsius, fahrenheit;

    std::cout << "Digite uma temperatura em Celsius: " << std::endl;
    std::cin >> celsius;
    std::cout << "Digite uma temperatura em Fahrenheit: " << std::endl;
    std::cin >> fahrenheit;

    std::cout << "A conversao da temperatura em Celsius para Fahrenheit eh: " << converteCelsiusFahrenheit(celsius) << std::endl;
    std::cout << "A conversao da temperatura em Fahrenheit para Celsius eh: " << converteFahrenheitCelsius(fahrenheit) << std::endl;

    return 0;
}