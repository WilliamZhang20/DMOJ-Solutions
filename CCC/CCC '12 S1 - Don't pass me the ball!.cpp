#include <iostream>

using namespace std;

int main() {
  int j, num=0;
  cin >> j;
  for(int i=3; i<=j-1; i++) {
    for(int k=2; k<=i-1; k++) {
      for(int l=1; l<=k-1; l++) {
        num++;
      }
    }
  }
  printf("%d\n", num);
}
