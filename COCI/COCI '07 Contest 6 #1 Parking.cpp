#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int numTrucks = 0;
  int cost = 0;
  int dep[3], arr[3];
  for(int i=0; i<3; i++) 
      cin >> arr[i] >> dep[i];
  for(int min = 0; min <= 100; min++) {
      for(int i=0; i<3; i++) {
          if(arr[i] == min) {
              numTrucks++;
          } 
          if(dep[i] == min) {
              numTrucks--;
          }
      }
      if(numTrucks==1) {
          cost+=a;
      }
      else if(numTrucks==2) {
          cost+=b*2;
      }
      else if(numTrucks==3) {
          cost+=c*3;
      }
  }
  cout << cost << endl;
}
