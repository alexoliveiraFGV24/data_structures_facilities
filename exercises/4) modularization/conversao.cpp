#include "conversao.h"

double converteCelsiusFahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = 1.8 * celsius + 32;
    return fahrenheit;
}

double converteFahrenheitCelsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}
