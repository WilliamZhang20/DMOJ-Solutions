#include <iostream>

using namespace std;

int main () {

  int numStations;
  int numRequired;
  int numWaves;
  
  int initial, final, addAmount;
  
  cin>>numStations;
  cin>>numRequired;
  cin>>numWaves;
  
  int stations[100000];
  int difference_array[100000] = {};
  
  for (int i=0; i<=numWaves-1; i++){
  	cin>> initial >> final >> addAmount; 
    difference_array[initial-1]+=addAmount; // adds to index of start station. This will be used in final stations array, which is prefix sum array of difference array. 
    difference_array[final]-=addAmount; // this line marks the end of the wave of troops, so prefix sum array stops adding k to the next station
  }
  
  int counter=0;
  stations[0] = difference_array[0];
  if(stations[0]<numRequired) {
    counter++;
  }

  for(int i=1; i<numStations; i++) {
    stations[i] = stations[i-1] + difference_array[i];
    if(stations[i]<numRequired) {
      counter++;
    }
  }
  cout<<counter<<endl;
  
  return 0;
}
