#include <bits/stdc++.h>

using namespace std;

int main() {
  // Using the Sieve of Eratosthenes to find number of primes betweeen open and close of interval.
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int open, close;
  int res;
  bool sieve[1000001];
  fill(begin(sieve), begin(sieve)+1000001, true);
  sieve[0] = false;
  sieve[1] = false;
  for(int i=2; i*i<=1000000; i++) {
      if(sieve[i]) {
          for(int j=i*2; j<=1000000; j+=i) {
              sieve[j]=false;
          }
      }
  }
  while(n--) {
    res = 0;
    cin >> open >> close;
    for(int i=open; i<close; i++) {
        if(sieve[i]) {
            res++;
        }
    }
    cout << res << endl;
  }
}
