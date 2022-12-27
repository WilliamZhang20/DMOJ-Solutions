#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double a, b;
  int v;
  double val1, val2; // the different zeros
  cin >> v;
  b = v; // b of equaiton
  a = (-9.8)/2; // a of quadratic equation of flare
  val1 = (-1*b + sqrt(pow(b, 2)-4*a))/(2*a); // Quadratic formula with plus
  val2 = (-1*b - sqrt(pow(b, 2)-4*a))/(2*a); // Quadratic formula with minus
  cout << setprecision(6) << setiosflags(ios::fixed|ios::showpoint) << abs(val2)-abs(val1) << endl; // Difference between absolute values of larger value and smaller zero is the time the flare will spend in the air
}
