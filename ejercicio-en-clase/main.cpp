/*
Autores: Nicolas Vidal & David Nino
*/


#include "cola-prioridad.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void print(Cola a){
    while(!a.vaciaCola()){
        cout << a.front() << endl;
        a.deque();
    }
}

int main(){
    Cola a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    a.enqueue(6);
    a.deque();

    cout << a.front() << endl;

    print(a);
    return 1;
}

