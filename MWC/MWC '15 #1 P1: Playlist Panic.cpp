#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int ans = 0;
  int x, y;
  int taken;
  cin >> n;
  int seconds[n];
  for(int i=0, m, s; i<n; i++) {
    cin >> m >> s;
    seconds[i] = m*60 + s;
  }
  cin >> x >> y;
  taken = x*60 + y; // convert to seconds
  sort(seconds, seconds+n);
  for(int i=0; i<n; i++) {
    if(seconds[i]>taken) {
      break;
    }
    taken-=seconds[i];
    ans++;
  }
  cout << ans << endl;
}
