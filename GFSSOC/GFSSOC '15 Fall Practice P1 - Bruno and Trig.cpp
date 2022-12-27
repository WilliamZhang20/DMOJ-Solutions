#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
  vector<int> triangle;
  int max = INT_MIN;
  int input, longest;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for(int i=0; i<3; i++) {
    cin >> input;
    triangle.push_back(input);
    if(triangle[i]>max) {
      max = triangle[i];
      longest = i;
    }
  }
  triangle.erase(triangle.begin()+longest); // Delete largest side length

  if(triangle[0]+triangle[1]<=max) { // used rule found online that sum of other two triangle sides should be smaller than largest side
    cout << "Maybe I should go out to sea...\n";
  } else {
    cout << "Huh? A triangle?\n";
  }
}
