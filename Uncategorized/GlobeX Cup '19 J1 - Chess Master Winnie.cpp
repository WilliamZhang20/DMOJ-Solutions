#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, a, b, c;
  int temp;
  int alien;
  cin >> n >> m >> a >> b >> c;
  bool status[n];
  for(int i=0; i<n; i++) {
    cin >> temp;
    temp == 0 ? status[i]=false: status[i]=true;
  }
  for(int i=0; i<c; i++) {
    cin >> alien;
    if(status[alien-1]==true) {
      m+=a;
    } else {
      m-=b;
    }
  }
  cout << m << endl;
}
