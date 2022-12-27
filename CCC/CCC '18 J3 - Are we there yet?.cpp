#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int diffs[4];
  int dists[5][5];
  for(int i=0; i<4; i++) {
    cin >> diffs[i];
  }
  dists[0][0] = 0;
  for(int i=1; i<5; i++) {
    dists[0][i] = diffs[i-1] + dists[0][i-1];
  }
  for(int i=1; i<5; i++) {
    for(int j=0; j<5; j++) {
      if(j<i) {
        dists[i][j] = dists[i-1][j]+diffs[i-1];
      } else if(j==i) {
        dists[i][j] = 0;
      } else {
        dists[i][j] = abs(dists[i-1][j]-diffs[i-1]);
      }
    }
  }
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      cout << dists[i][j] << " ";
    }
    cout << endl;
  }
}
