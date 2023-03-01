#include <stdio.h>

int calcular(int* store, int size){
  int min, max, i;
  min = store[0];
  max = min;
  for(i=1; i < size; i++){
    if(store[i] > max){
      max = store[i];
    }
    if(store[i] < min){
      min = store[i];
    }
  }  
  return (max - min)*2;
}

int main(void) {
  int tests, test, stores, i;
  int store[100];
  scanf("%d", &tests); // amount of tests (first line)

  for(test=1; test<=tests;test++){ 
    scanf("%d", &stores); // amount of stores (second line)
    for(i= 0; i<stores; i++){
      scanf("%d", &store[i]); // each store location
    }
    printf("%d\n",calcular(store, stores));
  }
  return 0;
}

