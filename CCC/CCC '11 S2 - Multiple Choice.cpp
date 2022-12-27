#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, count=0;
  cin >> n;
  char a[n], b[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
    if(a[i]==b[i]) {
      count++;
    }
  }
  cout << count <<endl;
}
