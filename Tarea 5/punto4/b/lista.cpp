#include "lista.h"

Lista::Lista() {
    act = NULL;
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

Lista Lista::operator + (Lista a) {
    /*
    COMPLEJIDAD:
        COMPLEJIDAD:
        a: cantidad de elementos dentro de la lista a
        b: cantidad de elementos dentro de la lista b
        -> O(a*b)

        El ciclo de la funcion tiene b iteraciones.
        En cada una de estas iteraciones hace un llamado al metodo .anxLista
        el cual tiene una complejidad O(a).

        Se tiene que llegar al final de la lista a por cada elemento de la lista b.
    */
    Lista l;
    if (!this->vaciaLista()) {
        for (int i = 1; i <= this->longLista(); i++) {
            l.anxLista(this->act->dato);
        }
    }
    if (!a.vaciaLista()) {
        for (int i = 1; i <= a.longLista(); i++) {
            l.anxLista(a.infoLista(i));
        }
    }
    
    return l;
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
