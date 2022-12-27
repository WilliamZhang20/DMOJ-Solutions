#include <bits/stdc++.h>
#define ll long long int
int sto[100000];
int dp[100000];

using namespace std;

int absDiff(int x, int y) {
  if(x-y>0) {
    return x-y;
  } else {
    return y-x;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> sto[i];
  }
  dp[0] = 0;
  for(int i=1; i<n; i++) {
    dp[i] = INT_MAX;
  }
  for(int i=0; i<n; i++) {
    for(int j=1; j<=k; j++) {
      dp[i+j] = min(dp[i+j], dp[i] + absDiff(sto[i], sto[i+j]));
    }
  }
  cout << dp[n-1] << endl;
}
