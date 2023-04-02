#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void football(){
  int t = 1, g = 1;
  while (t + g != 0){
    scanf("%d %d\n", &t, &g);
    vector<string> tn[100];
    char tmp[15];
    for(int team = 0; team < t; team++){
      scanf("%15s",&tn[team]);
    }
  }

}
int main() {
  football();
  return 1;
}