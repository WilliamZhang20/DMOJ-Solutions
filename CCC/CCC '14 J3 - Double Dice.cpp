#include <iostream>

using namespace std;

int main() {
  int n, a=100, d=100;
  scanf("%d", &n);
  int rolls[n][2];
  for(int i=0; i<n; i++) {
    scanf("%d", &rolls[i][0]);
    scanf("%d", &rolls[i][1]);
    if(rolls[i][0]<rolls[i][1]) {
      a-=rolls[i][1];
    } else if(rolls[i][0]>rolls[i][1]) {
      d-=rolls[i][0];
    }
  }
  printf("%d\n", a);
  printf("%d\n", d);
}
