#include <stdio.h>

void read(int *arr){
  int i = 0;
  while(scanf("%d", &arr[i]) != EOF){
    i++;
  }
}

int is_in(int target, int *arr){
  int answer = 0;
  int i = 0;
  while(arr[i] && answer == 0){
    if(arr[i] == target){
      answer = 1;
    }
    i++;
  }
  return answer;
}

int abs(int value){
  int correct = value;
  if(value<0){
    correct *= (-1);
  }
  return correct;
}

int main(void) {
  int flag, i, num[3000];
  
  i=1;
  flag = 1;
  read(num);
  
  while(num[i] && flag){
    if(is_in(abs(num[i]-num[i-1]), num)==0){
      flag = 0;
    }
    i++;
  }
  if(flag){
    printf("Jolly");
  }else{
    printf("Not Jolly");
  }
  return 0;
}