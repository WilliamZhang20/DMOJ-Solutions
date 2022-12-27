#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, a, b, k;
  cin >> t;
  int output[100] {0};
  int *primacity;
  for(int c=0; c<t; c++) {
    cin >> a >> b >> k;
    primacity = new int[b+1] {0};
    for(int i=2; i<=b; i++) {
      if(primacity[i]==0) {
        for (int j = i; j <= b; j += i)
          primacity[j]++;
      }
    }
    for(int i=a; i<=b; i++) {
      if(primacity[i]==k) {
        //cout << i << endl;
        output[c]++;
      }
    }
  }
  for(int i=0; i<t; i++) {
    cout << "Case #" << i+1 << ": " << output[i] << endl;
  }
}
