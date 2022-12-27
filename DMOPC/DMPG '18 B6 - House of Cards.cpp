#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  ll k;
  cin >> n >> k;
  ll w[n];
  for(int i=0; i<n; i++) {
    cin >> w[i];
  }
  sort(w, w+n);
  int j=n-2;
  ll prev = w[n-1];
  int num=1;
  while(j>=0) {
    if(prev-w[j]>=k) {
      prev = w[j];
      num++;
    } 
    j--;
  }
  cout << num << endl;
}
