#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int run = 1;
  int sz;
  while(run==1) {
    cin >> sz;
    if(sz==0) {
      run=0;
      break;
    }
    int *temps;
    temps = new int[sz];
    for(int i=0; i<sz; i++) {
      cin >> temps[i];
    }
    int *diffs = new int[sz-1]; // difference array
    for(int i=1; i<=sz-1; i++) {
      diffs[i-1] = temps[i]-temps[i-1];
    }
    vector<int> cycle;
    cycle.push_back(diffs[0]);
    int countCycles = 0;
    int shortest = 1;
    int j = 0;
    while(j<=sz-2) {
      if(diffs[j]==cycle[countCycles]) {
        if(countCycles==shortest-1) {
          countCycles=0;
        } else {
          countCycles++;
        }
        j++;
      }
      else {
        cycle.push_back(diffs[shortest]);
        shortest++;
        j = shortest;
      }
    }
    if(sz==1) {
      cout << "0" << endl;
    } else {
      cout << shortest << endl;
    }
  }
}
