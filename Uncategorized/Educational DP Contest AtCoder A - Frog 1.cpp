// Memoized
#include <bits/stdc++.h>

using namespace std;

int absDiff(int x, int y) {
  if(x-y>0) {
    return x-y;
  } else {
    return y-x;
  }
}

int main() {
  int n;
  cin >> n;
  int stones[n+1];
  for(int i=1; i<=n; i++) {
    cin >> stones[i];
  }
  int amount[100001];
  amount[n] = 0;
  amount[n-1] = absDiff(stones[n], stones[n-1]);
  for(int track = n-2; track>0; track--) {
    amount[track] = min(amount[track+1] + absDiff(stones[track], stones[track+1]), amount[track+2] + absDiff(stones[track], stones[track+2]));
  }
  cout << amount[1]  << endl;
}
