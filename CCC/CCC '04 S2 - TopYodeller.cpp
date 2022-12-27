#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  int input;
  int r[100], w[100];
  int *scores;
  scores = new int[n];
  for(int i=0; i<n; i++) {
    scores[i] = 0;
    w[i] = 0;
  }
  while(k--) {
    for(int i=0; i<n; i++) {
      cin >> input;
      scores[i] += input;
    }
    for(int i=0; i<n; i++) {
      int t = 1;
      for(int j=0; j<n; j++) {
        if(i!=j && scores[j] > scores[i]) {
          t++;
        }
      }
      if(t>w[i]) {
        w[i] = t;
      }
      r[i] = t;
    }
  }
  for(int i=0; i<n; i++) {
    if(r[i]==1) {
      cout << "Yodeller " << i+1 << " is the TopYodeller: score " << scores[i] << ", worst rank " << w[i] << endl;
    }
  }
}
