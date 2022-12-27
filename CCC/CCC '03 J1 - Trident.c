#include <stdio.h>

int main() {
  int t, s, h;
  scanf("%d", &t);
  scanf("%d", &s);
  scanf("%d", &h);
  //Prongs
  for(int i=0; i<t; i++) {
    printf("*");
    for(int j=0; j<s; j++) {
      printf(" ");
    }
    printf("*");
    for(int j=0; j<s; j++) {
      printf(" ");
    }
    printf("*\n");
  }
  //Horizontal line
  printf("*");
  for(int i=0; i<s; i++) {
    printf("*");
  }
  for(int i=0; i<s; i++) {
    printf("*");
  }
  printf("**\n");
  //Handle
  for(int i=0; i<h; i++) {
    for(int i=0; i<s+1; i++) {
      printf(" ");
    }
    printf("*\n");
  }
  return 0;
}
