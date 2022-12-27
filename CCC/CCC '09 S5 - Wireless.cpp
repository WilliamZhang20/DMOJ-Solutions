#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int eastWest; // counting streets
  int northSouth;
  int **city;
  int **diffs;
  int wireless; // number of shops with wireless
  cin >> eastWest >> northSouth >> wireless;
  city = new int*[eastWest+1];
  diffs = new int*[eastWest+1];
  for(int i=0; i<=eastWest; i++) {
    city[i] = new int[northSouth] {0};
    diffs[i] = new int[northSouth] {0};
  }
  int x, y, r, b;
  int upper, lower;
  int bound;
  while(wireless--) {
    cin >> x >> y >> r >>b;
    x--;
    y = eastWest-y;
    diffs[max(0, y-r)][x]+=b;
    diffs[min(eastWest, y+r+1)][x]-=b;
    for(int i=1; i<=r; i++) {
      // for each column, update difference array
      bound = floor((sqrt(r*r-i*i)));
      upper = max(0, y-bound);
      lower = min(eastWest, y+bound+1);
      /*cout << bound << " " << upper << " " << lower << endl;*/
      if(x-i>=0)  {
        diffs[upper][x-i]+=b;
        diffs[lower][x-i]-=b;
      }
      if(x+i<northSouth) {
        diffs[upper][x+i]+=b;
        diffs[lower][x+i]-=b;
      }
    }
    
  }
  int max = diffs[0][0];
  int maxOccur = 0;
  for(int i=0; i<northSouth; i++) {
    city[0][i] = diffs[0][i];
    if(city[0][i]>max) {
      max = city[0][i];
    }
  }
  for(int i=1; i<eastWest; i++) {
    for(int j=0; j<northSouth; j++) {
      city[i][j] = city[i-1][j] + diffs[i][j];
      if(city[i][j]>max) {
        max = city[i][j];
      }
    }
  }
  for(int i=0; i<eastWest; i++) {
    for(int j = 0; j<northSouth; j++) {
      if(city[i][j]==max) {
        maxOccur++;
      }
    } 
  }
  cout << max << endl << maxOccur << endl;
}
