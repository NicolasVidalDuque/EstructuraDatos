/*
Autor: Nicolas Vidal Duque
Fecha: Mayo 03 de 2023

Implementación TAD BigInteger

*/
#include "bigInteger.h"
#include <string>

using namespace std;

// Constuctor
BigInteger::BigInteger(string& s){
    /*
    COMPLEJIDAD: O(n) amortizado
        - n = Cantidad de caracteres dentro s
        - El ciclo usa "push_back" por cada iteracion. Esta operacion tiene complejidad O(1) amortizado
    */
    char a = '-';
    int i;

    // if first char == "-" -> negative #
    if(s[0] == a){
        this->positive = false;
        i = 1;
    } else {
        this->positive = true;
        i = 0;
    }

    for(i; i < s.size(); i++){
        this->vRepr.push_back(s[i] - 48);
    }
}

BigInteger::BigInteger(BigInteger& a){
    /*
    COMPLEJIDAD: O(n) amortizado
        - n = Cantidad de caracteres dentro s
        - "getIsPositive" tiene complejidad O(1)
        - "getLength" tiene complejidad O(1)
        - "getAtIndex" tiene complejidad O(1)
        - El ciclo usa "push_back" por cada iteracion. Esta operacion tiene complejidad O(1) amortizado
    */
    this->positive = a.getIsPositive();
    for(int i = 0; i < a.getLength();i++){
        this->vRepr.push_back(a.getAtIndex(i));
    }
}

// Get
int BigInteger::getAtIndex(int index){
    /*
    COMPLEJIDAD: O(1)
        - "size()" tiene complejidad O(1)
        - Acceder a un elemento en un vector tiene complejidad O(1) -> contiguo en memoria
    */
    int val = -1;
    if(index >= 0 && index < this->vRepr.size()){
        val = this->vRepr[index];
    }
    return val;
}

int BigInteger::getLength(){
    /*
    COMPLEJIDAD: O(1)
        - "size()" tiene complejidad O(1)
    */
    return this->vRepr.size();
}

bool BigInteger::getIsPositive(){
    /*
    COMPLEJIDAD: O(1)
        - Acceder a un atributo tiene complejidad O(1)
    */
    return this->positive;
}

// Set
void BigInteger::setIndex(int index, int value){
    /*
    COMPLEJIDAD: O(1)
        - "size()" tiene complejidad O(1)
        - Acceder y escribir en un elemento en un vector tiene complejidad O(1) -> contiguo en memoria
    */
    if(index >= 0 && index < this->vRepr.size()){
        this->vRepr[index] = value;
    }
}

string BigInteger::convertToString(){
    /*
    COMPLEJIDAD: O(n^3)
        - n = cantidad de digitos dentro del vector
        - "size()" tiene complejidad O(1)
        - Acceder a un elemento en un vector tiene complejidad O(1) -> contiguo en memoria
        - "to_String" tiene complejidad O(1)
        - "append (+)" tiene complejidad O(n^2)
    */
    string ans;
    if(!this->positive) ans += "-";
    for(int i = 0; i < this->vRepr.size(); i++){
        ans += to_string(this->vRepr[i]);
    }
    return ans;
}