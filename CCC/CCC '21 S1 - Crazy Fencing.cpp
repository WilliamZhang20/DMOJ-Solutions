#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;
  double totalArea=0;
  double areas[n];
  int height[n+1];
  int width[n];
  for(int i=0; i<n+1; i++) {
    cin >> height[i];
  } 
  for(int i=0; i<n; i++) {
    cin >> width[i];
    areas[i] = (height[i]+height[i+1])*width[i]*0.5;
    totalArea+=areas[i];
  }
  
  cout << fixed << totalArea << endl;
}
