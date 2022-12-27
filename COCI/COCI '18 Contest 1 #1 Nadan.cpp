#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> k >> n;
  for(int i=0; i<n-1; i++) {
    cout << i+1 << endl;
    k-=i+1;
  }
  cout << k << endl;
}
