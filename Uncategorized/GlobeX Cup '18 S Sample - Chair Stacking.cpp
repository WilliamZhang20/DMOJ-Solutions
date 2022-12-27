#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  ll dest_x, dest_y; // destination coordinates
  ll *x; 
  ll *y;
  cin >> n;
  x = new ll[n];
  y = new ll[n];
  for(int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
  }
  sort(x, x+n);
  sort(y, y+n);
  if(n%2==0) {
    dest_x = x[(n-1)/2+1];
    dest_y = y[(n-1)/2+1];
  } else {
    dest_x = x[(n-1)/2];
    dest_y = y[(n-1)/2];
  }
  ll time = 0;
  for(int i=0; i<n; i++) {
    if(x[i]-dest_x>0) {
      time += x[i]-dest_x;
    } else {
      time += dest_x-x[i];
    }
    if(y[i]-dest_y>0) {
      time += y[i]-dest_y;
    } else {
      time += dest_y-y[i];
    }
  }
  cout << time << endl;
}
