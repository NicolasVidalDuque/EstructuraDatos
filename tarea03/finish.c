#include <stdio.h>

int main(void) {
  int testCases, test, stations, station;
  int availableGas[100000];
  int requiredGas[100000];
  int totalGas[100000];
  int sum;
  int start;
  int car;
  scanf("%d\n", &testCases);
  
  for(test=1; test<=testCases; test++){
    scanf("%d\n", &stations);
    sum = 0;
    start = 0;
    car = 0;
    for(station=0; station<stations; station++){
      scanf("%d", &availableGas[station]);
    }
    for(station=0; station<stations; station++){
      scanf("%d", &requiredGas[station]);
      totalGas[station] = availableGas[station] - requiredGas[station];
      sum += totalGas[station];
    }
    if (sum > 0){
      for(station=0; station<stations;station++){
        car += totalGas[station];
        if (car <0){
          car = 0;
          start = station + 1;
        }
      }
    }
    if(sum <0){
      printf("Case %d: Not possible\n", test);
    }else{
      printf("Case %d: Possible from station %d\n", test, start+1);
    }
    
  }
  return 0;
}