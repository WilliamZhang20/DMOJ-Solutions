#include <bits/stdc++.h>

using namespace std;

int smallestDivisor(int n, int d=2) {
  if(n%d==0) {
    return d;
  } 
  else {
    return smallestDivisor(n, d+1);
  }
}

bool isPrime(int n, int i = 2)
{
    // Base cases
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
 
    // Check for next divisor
    return isPrime(n, i + 1);
}

int main() {
  int n;
  int small, big;
  cin >> n;
  if(isPrime(n)) {
    big = 1;
  }
  else if(n!=1) {
    small = smallestDivisor(n);
    big = n / small;
  } 
  else {
    small = 0;
    big = n;
  }
  cout << n-big << endl;
}
