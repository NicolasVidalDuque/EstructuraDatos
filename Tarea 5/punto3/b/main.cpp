#include "lista.h"
#include <iostream>

using namespace std;

int main() {
    Lista l;
    l.insListaOrdenada(5);
    l.insListaOrdenada(10);
    l.insListaOrdenada(12);
    l.insListaOrdenada(15);

    l.insListaOrdenada(11);

    return 0;
}
