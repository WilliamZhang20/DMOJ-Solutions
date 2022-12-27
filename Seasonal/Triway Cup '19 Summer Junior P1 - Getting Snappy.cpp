#include <iostream>
#include <cmath>

using namespace std;

int reduce(int n, int m) {
  int next = floor(n/2);
  if(next<m) {
    if((n-m)<(m-next)) {
      return n;
    } else if((n-m)==(m-next)) {
      return n;
    } else {
      return next;
    }
  } 
  else {
    return reduce(next, m);
  }
}

int main() {
  int n;
  int m;
  int papayas;
  cin >> n >> m;
  papayas = reduce(n, m);
  cout << papayas << endl;
}
