#include "lista.h"
#include <iostream>

using namespace std;

void insertarEnListaOrdenada(Lista& l, int value) {

    /*
    COMPLEJIDAD:
      n: cantidad de numeros menores a value -> O(n^2)

      Por cada elemento de la lista en el ciclo_i se tiene que recorrer mediante el metodo .infoLista hasta la posicion i. 

      Se hace n llamados al metodo .infolista, cuyo costo es de O(n). Por lo tanto resulta en complejidad cuadratica.
    */

    bool b = true;
    int lon = l.longLista();
    if (lon == 0) {
        l.anxLista(value);
        b = false;
    }
    for (int i = 1; i <= lon && b; i++) {
        if (l.infoLista(i) >= value) {
            b = false;
            l.insLista(value, i);
        }
    }
    if (b) {
        l.anxLista(value);
    }
}

int main() {
    Lista l;
    insertarEnListaOrdenada(l, 10);
    insertarEnListaOrdenada(l, 12);
    insertarEnListaOrdenada(l, 15);
    insertarEnListaOrdenada(l, 5);
    insertarEnListaOrdenada(l, 11);

    return 0;
}
