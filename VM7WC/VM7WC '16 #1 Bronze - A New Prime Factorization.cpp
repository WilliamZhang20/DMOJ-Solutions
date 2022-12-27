#include <iostream>

using namespace std;

int i=2;
void printPrimes_r(int n) {
  if(n<=1) {
    return;
  } else if(n%i==0) {
    cout << i << endl;
    n/=i;
    i=2;
    printPrimes_r(n);
  } else {
    i++;
    printPrimes_r(n);
  }
}

int main() {
  int y;
  cin >> y;
  printPrimes_r(y);
  return 0;
}
