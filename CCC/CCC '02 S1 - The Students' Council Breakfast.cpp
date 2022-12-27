#include <iostream>
#include <climits>

using namespace std;

int main() {
  int numCombos=0;
  int amount;
  int pink, green, red, orange;
  cin >> pink >> green >> red >> orange;
  cin >> amount;
  int minimum=INT_MAX;
  for(int i=0; i<=amount; i++) {
    for(int j=0; j<=amount; j++) {
      for(int k=0; k<=amount; k++) {
        for(int l=0; l<=amount; l++) {
          if(pink*i+green*j+red*k+orange*l==amount) {
            cout << "# of PINK is " << i << " # of GREEN is " << j << " # of RED is " << k << " # of ORANGE is " << l << "\n";
            numCombos++;
            if(minimum>i+j+k+l && i+j+k+l!=0) {
              minimum=i+j+k+l;
            }
          }
        }
      }
    }
  }
  cout << "Total combinations is " << numCombos << ".\n";
  cout << "Minimum number of tickets to print is " << minimum << ".\n";
}
