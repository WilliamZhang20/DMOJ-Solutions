#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n, k, d;
  int users;
  cin >> n >> k >> d;
  users = n;
  for(int i=0; i<d; i++) {
      users*=k;
  }
  // users = n*pow(k, d);
  cout << users << endl;
}
