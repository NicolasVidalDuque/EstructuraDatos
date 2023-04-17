#include "lista.h"
#include <iostream>

using namespace std;

void im(Lista& l) {
    for (int i = 1; i <= l.longLista(); i++) {
        cout << l.infoLista(i) << " ";
    }
    cout << endl;
}

int main() {
    Lista a, b, c;
    
    b.anxLista(2);
    b.anxLista(2);
    b.anxLista(2);
    b.anxLista(2);
    b.anxLista(2);
    b.anxLista(2);

    
    c = a + b;
    im(c);
    return 0;
}
