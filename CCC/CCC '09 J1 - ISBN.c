#include <stdio.h>
// CCC 2009 J1

int main() {
  int a, b, c;
  int sum;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  // Number always starts with 9780921418 with 3 digits input by the user
  // Therefore, the initial sum must be:
  sum=9+21+8+0+9+6+1+12+1+24;
  sum+=a+b*3+c;
  printf("The 1-3-sum is %d\n", sum);
  return 0;
}
