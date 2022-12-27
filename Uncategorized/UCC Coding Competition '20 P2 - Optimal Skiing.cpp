#include <iostream>

using namespace std;

int main() {
  int n; // number of ski lift routes
  int shortestTime=100000000; //Initialized to very big number to find shortest time
  int liftTimes[100]; // Problem states that max number of lift times is 100
  int sums[100] = {0}; // The {0} initializes all elements in the array to zero
  int sz;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> sz;
    for(int j=0; j<sz; j++) {
      cin >> liftTimes[j];
      sums[i]+=liftTimes[j]; // Obtaining total time for that lift route.
    }
    if(sums[i]<shortestTime) {
      shortestTime=sums[i]; // Replace shortestTime if we find a shorter time
    }
  }
  cout << shortestTime << endl; // Shortest lift route time
}
