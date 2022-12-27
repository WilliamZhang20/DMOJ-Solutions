#include <iostream>

using namespace std;

int main() {
  string str;
  int numWords = 1; 
  getline(cin, str);
  for(int i=0; i<str.size(); i++) {
    if(str[i]==' ') {
      numWords++;
    }
  }
  cout << numWords << endl;
}
