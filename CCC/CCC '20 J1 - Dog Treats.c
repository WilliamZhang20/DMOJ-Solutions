#include <stdio.h>

int main() {
  int s, m, l, score;
  scanf("%d", &s);
  scanf("%d", &m);
  scanf("%d", &l);
  score = 1*s + 2*m + 3*l;
  if(score>=10) {
    printf("happy\n");
  }
  else {
    printf("sad\n");
  }
  return 0;
}
