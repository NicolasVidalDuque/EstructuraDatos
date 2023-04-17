#include "lista.h"

Lista::Lista() {
    act = NULL;
}

void Lista::insListaOrdenada(Elemento e) {
    /*
    COMPLEJIDAD:
      n: cantidad de numeros menores a e -> O(n)

      Este metodo solo recorre la lista hasta que encuentra el primer elemento mayor que el numero a incertar. 
    */
    
    bool b = true;
    Nodo * n = new Nodo;
    n->dato = e;
    n->sig = NULL;
    Nodo* tmp = act;

    if (act == NULL) {
        act = n;
    } else {
        while (tmp->sig != NULL && b) {
            if (e > tmp->sig->dato) {
                tmp = tmp->sig;
            }
            else {
                b = false;
            }
        }
        if (b) {
            tmp->sig = n;
        }
        else {
            n->sig = tmp->sig;
            tmp->sig = n;
        }
    }
}

void Lista::anxLista(Elemento elem) {
    Nodo* tmp;
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->sig = NULL;

    if (act == NULL)
        act = nuevo;
    else {
        tmp = act;
        while (tmp->sig != NULL)
            tmp = tmp->sig;
        tmp->sig = nuevo;
    }
}

void Lista::insLista(Elemento elem, int pos) {
    Nodo* nuevo, * tmp;
    nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->sig = NULL;

    if (pos >= 1 && pos <= longLista()) {
        if (pos == 1) {
            nuevo->sig = act;
            act = nuevo;
        }
        else {
            tmp = act;
            for (int i = 0; i < pos - 2; i++)
                tmp = tmp->sig;
            nuevo->sig = tmp->sig;
            tmp->sig = nuevo;
        }
    }
}

void Lista::elimLista(int pos) {
    Nodo* tmp, * elim;
    if (pos >= 1 && pos <= longLista()) {
        if (pos == 1)
            act = act->sig;
        else {
            tmp = act;
            for (int i = 0; i < pos - 2; i++)
                tmp = tmp->sig;
            elim = tmp->sig;
            tmp->sig = tmp->sig->sig;
            delete elim;
        }
    }
}

Elemento Lista::infoLista(int pos) {
    Nodo* tmp = act;

    for (int i = 1; i < pos; i++)
        tmp = tmp->sig;

    return tmp->dato;
}

int Lista::longLista() {
    Nodo* tmp = act;
    int cont = 0;

    while (tmp != NULL) {
        tmp = tmp->sig;
        cont++;
    }

    return cont;
}

bool Lista::vaciaLista() {
    return act == NULL;
}
