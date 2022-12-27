#include <bits/stdc++.h>

using namespace std;

long long int gcd(int x, int y) {
  return y ? gcd(y, x%y) : x;
}

long long int largestPrime(long long int n) {
  long long int maxPF = 1;
  while (n % 2 == 0) {
    maxPF = 2;
    n /= 2;
  }
  for (int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      maxPF = i;
      n = n / i;
      if(maxPF==-1) {
        cout << maxPF << endl;
      }
    }
  }
  if(n>2)
    maxPF = n;
  return maxPF;
}

int main() {
  int n;
  long long int res;
  cin >> n;
  vector<long long int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  long long int gcdOfNums = a[0];
  for(int i=1; i<n; i++) {
    gcdOfNums = gcd(gcdOfNums, a[i]);
  }
  res = largestPrime(gcdOfNums);
  res!=1? cout << res << endl: cout << "DNE\n";

  return 0;
}
