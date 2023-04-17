#include "lista.h"
#include <iostream>

using namespace std;

int contarOcurrencias(Lista l, int value){
  /*
  COMPLEJIDAD:
    n: Cantidad de nodos en la lista -> O(n^2)

    La funcion recurre al metodo .infoLista(i), lo que implica 
    que por cada iteracion del ciclo en la funcion contarOcurrencias()
    tiene que recorrer i veces la lista. Al final termina recorriendo la lista
    n^2 veces cuando esta buscando en el ultimo elemento.
  */
  int ans = 0;
  if(!l.vaciaLista()){
    for(int i = 1; i <= l.longLista(); i++){
      if(l.infoLista(i) == value){
        ans++;
      }
    }
  }
  return ans;
}

Lista obtenerMenores(Lista l, int value){
  /*
  COMPLEJIDAD:
    n: Cantidad de nodos en la lista -> O(n^2)

    La funcion recurre al metodo .infoLista(i), lo que implica 
    que por cada iteracion del ciclo en la funcion contarOcurrencias()
    tiene que recorrer i veces la lista. Al final termina recorriendo la lista
    n^2 veces cuando esta buscando en el ultimo elemento.
  */
  Lista a;
  if(!l.vaciaLista()){
    for(int i = 1; i <= l.longLista(); i++){
      int v = l.infoLista(i);
      if(v < value){
        a.anxLista(v);
      }
    }
  }
  return a;
}

int main(){
  Lista l;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);

  contarOcurrencias(l, 10);
  obtenerMenores(l, 10);


  

  return 0;
}
