/*
Autores: Nicolas Vidal & David Nino
*/

#include "cola-prioridad.h"
#include <algorithm>

Cola::Cola(){
}

int Cola::front(){
    // COMPLEJIDAD: O(n)
    int ans = vec[vec.size() - 1];
    return ans;
}

void Cola::enqueue(int e){
    /*
    COMPLEJIDAD: O(n log(n))
        - n = cantidad de elementos dentro del vector
        - insertar un elemento al inicio del vector -> O(n)
        - sort() -> O(n log(n))
    */
    vec.insert(vec.begin(), e);
    sort(vec.begin(), vec.end());
}

void Cola::deque(){
    /*
    COMPLEJIDAD: n log(n)
        - n = cantidad de elementos dentro del vector
        - insertar un elemento al inicio del vector -> O(n)
        - sort() -> O(n log(n))
    */
    vec.pop_back();
    sort(vec.begin(), vec.end());
}

bool Cola::vaciaCola(){
    // COMPLEJIDAD: O(1) -> .empty() es constante
  bool ans;
  if(vec.empty())
     ans = true;
  else
     ans = false;
  return ans;
}
