#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool between(int a, int b, int c) {
  return a<=b && b<=c;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll a, b;
  cin >> a >> b;
  vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
  int n;
  int next;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> next;
    motels.push_back(next);
  }
  sort(motels.begin(), motels.end());
  int sz = motels.size();
  vector<ll> dp(sz);
  for(int i=0; i<sz; i++) { // finding motels reachable from starting point
    if(between(a, motels[i], b)) {
      dp[i] = 1;
    } else {
      dp[i] = 0;
    }
  }
  for(int i=0; i<sz; i++) {
    if(dp[i]>0) {
      for(int j=0; j<sz; j++) {
        if(between(a, motels[j]-motels[i], b)) {
          dp[j] = dp[j] + dp[i];
        }
      }
    }
  }
  cout << dp[sz-1] << endl;
}
