#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a[8];
  int mushrooms[8];
  int j = 0;
  int output;
  int k, l, m;
  for(int i=0; i<8; i++) {
    cin >> a[i];
  }
  while(j<8) {
    if(j<=4) {
      k = j+1;
      l = j+2;
      m = j+3;
    } else if(j==5) {
      k = j+1;
      l = j+2;
      m = 0;
    } else if(j==6) {
      k = j+1;
      l = 0;
      m = 1;
    } else if(j==7) {
      k = 0;
      l = 1;
      m = 2;
    }
    mushrooms[j] = a[j]+a[k]+a[l]+a[m];
    j++;
  }
  output = mushrooms[0];
  for(int i=0; i<8; i++)
   {
    if(output < mushrooms[i])
     output = mushrooms[i];
   }
  cout << output << endl;
}
