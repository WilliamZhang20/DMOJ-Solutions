#include <iostream>

using namespace std;

int main() {
  int n;
  int numPink=0;
  cin >> n;
  int r[n], g[n], b[n];
  for(int i=0; i<n; i++) {
    cin >> r[i] >> g[i] >> b[i];
    while(r[i]<=255 && r[i]>=240 && g[i]>=0 && g[i]<=200 && b[i]<=220 && b[i]>=95) {
      numPink++;
      break;
    }
  }
  cout << numPink << endl;
}
