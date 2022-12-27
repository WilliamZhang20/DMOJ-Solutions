#include <iostream>
#include <climits>

using namespace std;

int main() {
  int p;
  int len, width;
  cin >> p;
  int x[p], y[p];
  int fencing;
  int minX=INT_MAX, maxX=INT_MIN;
  int minY=INT_MAX, maxY=INT_MIN;
  for(int i=0; i<p; i++) {
    cin >> x[i] >> y[i];
    if(x[i]<minX) {
      minX=x[i];
    }
    if(x[i]>maxX) {
      maxX=x[i];
    }
    if(y[i]<minY) {
      minY = y[i];
    }
    if(y[i]>maxY) {
      maxY = y[i];
    }
  }
  len = maxX-minX;
  width = maxY-minY;
  fencing = 2*len+2*width;
  cout << fencing << endl;
}
