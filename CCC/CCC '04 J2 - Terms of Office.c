#include <stdio.h>

int main() {
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);
  for(int i=x; i<=y; i+=60) {
    printf("All positions change in year %d\n", i);
  }
  return 0;
}
