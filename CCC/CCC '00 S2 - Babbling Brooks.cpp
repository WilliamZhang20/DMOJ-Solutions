#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<double> brooks;
  int n;
  double input;
  int stream;
  double perc;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> input;
    brooks.push_back(input);
  }
  while(true) {
    cin >> input;
    if(input == 77) { // end of input
      break; 
    } else if(input == 99) { // split
      cin >> stream;
      cin >> perc;
      brooks.insert(brooks.begin()+stream, (brooks[stream-1]*(100-perc))/100);
      brooks[stream-1] -= brooks[stream];
    } else if(input == 88) {
      cin >> stream;
      brooks[stream] += brooks[stream-1];
      brooks.erase(brooks.begin()+stream-1);
    }
  }
  for(double a: brooks) {
    cout << round(a) << " ";
  }
  cout << endl;
}
