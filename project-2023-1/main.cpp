/*
Autor: Nicolas Vidal Duque
Fecha: Mayo 03 de 2023

Implementación TAD BigInteger

*/

#include "bigInteger.h"
#include <iostream>
#include <string>

int main(){
    string a;
    std::cout << "Escribir Numero:  ";
    std::cin >> a;
    std::cout << endl;
    BigInteger b(a);
    BigInteger c(b);
    std::cout << c.convertToString();


    return 0;
}