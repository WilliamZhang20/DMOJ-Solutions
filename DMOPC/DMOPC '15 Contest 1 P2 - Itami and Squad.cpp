#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n; // number of soldiers
  int numLeaders;
  int itami;
  cin >> n;
  cin >> numLeaders;
  cin >> itami;
  int squad = 0;
  int strength[n];
  for(int i=0; i<n; i++) {
    cin >> strength[i];
  }
  sort(strength, strength + n, greater<int>());
  for(int i = itami-1; i<n; i+=numLeaders) {
    // update counter is decided by the fact that the soldiers are picked like this: highest ranking leader choses one, next highest another, and so on. If there are soldiers left after first round, they go back to the highest ranking and continue.
    squad += strength[i]; 
  }
  cout << squad << endl;
}
