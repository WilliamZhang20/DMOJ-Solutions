#include <bits/stdc++.h>

using namespace std;

void printFraction(int x, int y) {
  int d = __gcd(x, y);
  x = x / d;
  y = y / d;
  cout << x << "/" << y << "\n";
}

int main() {
  int numerator, denominator;
  cin >> numerator >> denominator;
  if(numerator % denominator == 0) {
    cout << numerator/denominator << endl;
  } else {
    if(numerator/denominator!=0)
      cout << floor(numerator/denominator) << " ";
    printFraction(numerator%denominator, denominator);
  }
}
