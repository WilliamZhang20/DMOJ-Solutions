#include <bits/stdc++.h>
// recursive implementation
using namespace std;

bool ready[10000];
int dp[10000];
int n;

int solve(int a, int coins[]) {
  int best = 10000;
  if(a<0) {
    return 10000;
  }
  if(a==0) {
    return 0;
  }
  if(ready[a]) {
    return dp[a];
  }
  for(int i=0; i<n; i++) {
    best = min(best, solve(a-coins[i], coins)+1);
  }
  dp[a] = best;
  ready[a] = true;
  return dp[a];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x;
  cin >> x;
  cin >> n;
  int coins[n];
  for(int i=0; i<n; i++) {
    cin >> coins[i];
  }
  cout << solve(x, coins) << endl;
}
