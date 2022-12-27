#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long int w, n;
  int output=-1, temp=0;
  cin >> w;
  cin >> n;
  long long int weights[n];
  for(int i=0; i<n; i++) {
    cin >> weights[i];
  }
  for(int i=0; i<n; i++) {
    if(weights[i]+weights[i+1]+weights[i+2]+weights[i+3]>w) {
      for(int j=0; j<=3; j++) {
        temp+=weights[i+j];
        if(temp>w) {
          output = i+j; 
          break;
        }
      }
      break;
    } 
  }
  if(output==-1) {
    output = n;
  }
  cout << output << endl;
}
