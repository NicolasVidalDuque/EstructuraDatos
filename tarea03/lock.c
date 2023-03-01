#include <stdio.h>
// 0 10 0 10
// 0-10 = -10 > -10+40 = 30 > 30%40 = 10
int main() {
  const int NUMS = 4;
  const int DEGREES = 360;
  const int TICKS = 40;
  
  int combination[NUMS];
  int steps = TICKS*3;
  
scanf("%d %d %d %d",&combination[0],&combination[1],&combination[2],&combination[3]);

  while(combination[0]+combination[1]+combination[2]+combination[3] > 0){

    steps += (combination[0] - combination[1] + TICKS)%TICKS;
    steps += (combination[2] - combination[1] + TICKS)%TICKS;
    steps += (combination[2] - combination[3] + TICKS)%TICKS;
    printf("%d\n", steps*(DEGREES/TICKS));
    scanf("%d %d %d %d",&combination[0],&combination[1],&combination[2],&combination[3]);
    steps = TICKS*3;
    
  }
    return 0;
}
