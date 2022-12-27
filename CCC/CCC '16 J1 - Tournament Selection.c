#include <stdio.h>

int main() {
  char stat[12];
  int win=0, i; 
  for(i=0; i<12; i++) {
    scanf("%c", &stat[i]);
    if(stat[i] == 'W') {
      win++;
    }
  }
  if(win==6 || win==5) {
    printf("1\n");
  }
  else if(win==3 || win==4) {
    printf("2\n");
  }
  else if(win==1 || win==2) {
    printf("3\n");
  }
  else if(win==0) {
    printf("-1\n");
  }
  return 0;
}
