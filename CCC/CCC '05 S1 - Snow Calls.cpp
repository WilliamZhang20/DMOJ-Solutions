#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  string numbers[t];
  for(int i=0; i<t; i++) {
    cin >> numbers[i];
    numbers[i].erase(remove(numbers[i].begin(), numbers[i].end(), '-'), numbers[i].end());
    /*cout << "Removed dashes\n";
    cout << numbers[i] << endl;*/
    numbers[i] = numbers[i].substr(0, 10);
    /*cout << "Truncated\n";
    cout << numbers[i] << endl;*/
    for(int j=0; j<numbers[i].size(); j++) {
      if(numbers[i][j]=='A' || numbers[i][j]=='B' || numbers[i][j]=='C') {
        numbers[i][j]='2';
      } else if(numbers[i][j]=='D' || numbers[i][j]=='E' || numbers[i][j]=='F') {
        numbers[i][j]='3';
      } else if(numbers[i][j]=='G' || numbers[i][j]=='H' || numbers[i][j]=='I') {
        numbers[i][j]='4';
      } else if(numbers[i][j]=='J' || numbers[i][j]=='K' || numbers[i][j]=='L') {
        numbers[i][j]='5';
      } else if(numbers[i][j]=='M' || numbers[i][j]=='N' || numbers[i][j]=='O') {
        numbers[i][j]='6';
      } else if(numbers[i][j]=='P' || numbers[i][j]=='Q' || numbers[i][j]=='R' || numbers[i][j]=='S') {
        numbers[i][j]='7';
      } else if(numbers[i][j]=='T' || numbers[i][j]=='U' || numbers[i][j]=='V') {
        numbers[i][j]='8';
      } else if(numbers[i][j]=='W' || numbers[i][j]=='X' || numbers[i][j]=='Y' || numbers[i][j]=='Z') {
        numbers[i][j]='9';
      } 
    }
    /*cout << "Conversion Done\n";
    cout << numbers[i] << endl;*/
    // Add back dashes
    numbers[i].insert(numbers[i].begin()+3, '-');
    numbers[i].insert(numbers[i].begin()+7, '-');
  }
  for(auto a: numbers) {
    cout << a << endl;
  }
}
