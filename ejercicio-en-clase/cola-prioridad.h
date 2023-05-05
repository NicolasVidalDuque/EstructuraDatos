#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H


#include <vector>

using namespace std;

class Cola{
   vector<int> vec;

   public:
      Cola(); // crearCola
      int front();
      void deque();
      void enqueue(int);
      bool vaciaCola();
      bool greater(int a, int b);
};

#endif