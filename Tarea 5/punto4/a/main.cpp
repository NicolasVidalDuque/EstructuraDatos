#include "lista.h"
#include <iostream>

using namespace std;

void concatenarListas(Lista &a, Lista &b) {
    /*
    COMPLEJIDAD:
        a: cantidad de elementos dentro de la lista a
        b: cantidad de elementos dentro de la lista b
        -> O(a*b)

        El ciclo de la funcion tiene b iteraciones.
        En cada una de estas iteraciones hace un llamado al metodo .anxLista
        el cual tiene una complejidad O(a).

        Se tiene que llegar al final de la lista a por cada elemento de la lista b.
    */
    int lon;
    if (!b.vaciaLista()) {
        lon = b.longLista();
        for (int i = 1; i <= lon; i++) {
            a.anxLista(i);
        }
    }
}

int main() {
    Lista a, b;
    b.anxLista(1);
    b.anxLista(2);
    b.anxLista(3);
    b.anxLista(4);
    b.anxLista(5);

    concatenarListas(a, b);
    return 0;
}
