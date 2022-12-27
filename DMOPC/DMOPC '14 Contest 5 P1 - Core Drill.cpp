#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int r, h;
  double volume;
  double PI = 3.141592653589793;
  cin >> r >> h;
  volume = (PI * pow(r, 2) * h)/3;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout << setprecision(2);
  cout << volume;
}
