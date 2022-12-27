#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
  }
  int pointsF=0, pointsX=0;
  for(int k=0; k<n; k++) {
    if(a[k]>b[k]) {
      pointsX++;
    } else if(a[k]<b[k]) {
      pointsF++;
    }
  }
  cout << pointsX << " " << pointsF << endl;
  if(pointsF>pointsX) {
    cout << "FatalEagle\n";
  } else if(pointsF<pointsX) {
    cout << "Xyene\n";
  } else {
    cout << "Tie\n";
  }
}
