#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int coders[n];
  bool copies[n];
  int numSources = n;
  for(int i=0; i<n; i++) {
    copies[i]=false;
  } 
  for(int i=0; i<n; i++) {
    cin >> coders[i];
    coders[i]--;
    if(coders[i]>=0)
      copies[coders[i]]=true;
  }
  for(int i=0; i<n; i++) {
    if(copies[i]) {
      numSources--;
    }
  }
  cout << numSources << endl;
}
