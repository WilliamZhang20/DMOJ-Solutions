#include <iostream>

using namespace std;

int main() {
  int k;
  scanf("%d", &k);
  // First third
  for(int i=0; i<k; i++) {
    for(int j=0; j<k; j++) {
      printf("*");
    }
    for(int j=0; j<k; j++) {
      printf("x");
    }
    for(int j=0; j<k; j++) {
      printf("*");
    }
    cout << endl;
  }
  // Second third
  for(int i=0; i<k; i++) {
    for(int j=0; j<k; j++) {
      printf(" ");
    }
    for(int j=0; j<2*k; j++) {
      printf("x");
    }
    cout << endl;
  }
  // Last section 
  for(int i=0; i<k; i++) {
    for(int j=0; j<k; j++) {
      printf("*");
    }
    for(int j=0; j<k; j++) {
      printf(" ");
    }
    for(int j=0; j<k; j++) {
      printf("*");
    }
    cout << endl;
  }
}
