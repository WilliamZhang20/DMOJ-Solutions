#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int radius, i=0;
  vector<int> pennies;
  double r2, x2; 
  cin >> radius;
  while(radius!=0) {
    pennies.push_back(0);
    r2 = (double) (radius * radius);
    for(int x=1; x<=radius; x++) {
      x2 = (double) x*x;
      pennies[i] += floor((sqrt(r2-x2))) + 1; // +1 to add penny on x-axis
    }
    pennies[i] = 4 * pennies[i] + 1; // Accouning for quadrants and origin
    cin >> radius;
    i++;
  }
  for(auto a: pennies) {
    cout << a << endl;
  }
}
