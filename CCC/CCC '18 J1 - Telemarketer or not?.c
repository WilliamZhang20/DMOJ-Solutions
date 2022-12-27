#include <stdio.h>
#include <stdbool.h>
/*Refer to https://dmoj.ca/problem/ccc18j1*/

int main(void) {
  bool isTelemarketer;
  int a[4];
  for(int i=0; i<4; i++) {
    scanf("%d", &a[i]);
  }
  if((a[0]==8 || a[0]==9) && a[1]==a[2] && (a[3]==8 || a[3]==9)) {
    isTelemarketer = true;
  }
  else {
    isTelemarketer = false;
  }
  if(isTelemarketer==true) {
    printf("ignore\n");
  }
  else {
    printf("answer\n");
  }
  return 0;
}
