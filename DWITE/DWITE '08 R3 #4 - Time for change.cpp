#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x;
  int n;
  int counter = 5;
  while(counter--) {
    cin >> x;
    cin >> n;
    int coins[n];
    for(int i=0; i<n; i++) {
      cin >> coins[i];
    }
    vector<int> memo(x+1);
    for(int i=1; i<=x; i++) {
      memo[i] = 1e4;
      for(int j = 0; j<n; j++) {
        if(i>=coins[j]) {
          memo[i] = min(memo[i], 1 + memo[i-coins[j]]);
        }
      }
    }
    cout << memo[x] << endl;
  }
}
