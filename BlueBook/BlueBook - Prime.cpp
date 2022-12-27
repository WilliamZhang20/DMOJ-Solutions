#include <iostream>

using namespace std;

bool isPrime_r(int n, int i = 2)
{
    // Base cases
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
 
    // Check for next divisor
    return isPrime_r(n, i + 1);
}

int main() {
  int t;
  int n;
  cin >> t;
  for(int j=0; j<t; j++) {
    cin >> n;
    isPrime_r(n, 2)? cout << 1 << endl: cout << 0<< endl;
  }
}
