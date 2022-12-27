#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  int uglies = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  if(a[0]<=41 && a[1]<=41) {
    uglies++;
  }
  for(int i=1; i<n-1; i++) {
    if(a[i-1]<=41 && a[i]<=41 && a[i+1]<=41) {
      uglies++;
    }
  }
  if(a[n-1]<=41 && a[n-2]<=41) {
    uglies++;
  }
  cout << uglies << endl;
}
