/*
Autor: Nicolas Vidal Duque
Fecha: Mayo 03 de 2023

Implementación TAD BigInteger

*/

#ifndef  BIGINTEGER_H
#define BIGINTEGER_H

#include <string>
#include <vector>
using namespace std;

class BigInteger{
    private:
        vector<int> vRepr;
        bool positive; // +: true, -: false

    public:
        // Constructor
        BigInteger(string&);
        BigInteger(BigInteger&);

        // Get
        int getAtIndex(int index);
        int getLength();
        bool getIsPositive();

        // Set
        void setIndex(int index, int value);

        // Operations
        void add(BigInteger&);
        void product(BigInteger&);
        void substract(BigInteger&);
        void quotient(BigInteger&);
        void remainder(BigInteger&);
        void pow(BigInteger&);

        string convertToString();
        BigInteger operator+(BigInteger&);
        BigInteger operator-(BigInteger&);
        BigInteger operator*(BigInteger&);
        BigInteger operator/(BigInteger&);
        BigInteger operator%(BigInteger&);
        BigInteger operator==(BigInteger&);
        BigInteger operator<(BigInteger&);
        BigInteger operator<=(BigInteger&);
        BigInteger sumarListaValores(vector<BigInteger>&);
        BigInteger multipicarListaValores(vector<BigInteger>&);

};

#endif
