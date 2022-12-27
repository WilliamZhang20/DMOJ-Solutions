#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int length;
  int height;
  int obstacle;
  cin >> length;
  cin >> height;
  int obst_at_h[500001] {0};
  int diffs[500001] {0};
  for(int i=0; i<length; i++) {
    cin >> obstacle;
    if(i%2==0) {
      diffs[0]++;
      diffs[obstacle]--;
    } else {
      diffs[height-obstacle]++;
      diffs[height]--;
    }
  }
  obst_at_h[0] = diffs[0];
  for(int i=1; i<height; i++) {
    obst_at_h[i] = obst_at_h[i-1] + diffs[i];
  } 
  int min = *min_element(obst_at_h, obst_at_h+height);
  int occur = 0;
  for(int i=0; i<height; i++) {
    if(obst_at_h[i]==min) {
      occur++;
    }
  }
  cout << min << " " << occur << endl;
}
