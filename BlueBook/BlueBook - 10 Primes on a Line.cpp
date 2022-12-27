#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

bool isPrime_r(ll n, ll i = 2)
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
  ll n;
  ll i=0;
  ll j=2;
  vector<ll> list;
  cin >> n;
  while(i<n) {
    if(isPrime_r(j)) {
      list.push_back(j);
      i++;
    }
    j++;
  }
  ll k;
  for(k=0; k<list.size(); k++) {
    cout << list[k] << " ";
    if((k+1)%10==0) {
      cout << endl;
    }
  } 
  k%10==0? cout << "": cout << endl;
}
