#include <iostream>
#include <string>

using namespace std;

int main() {
  string verb;
  string object;
  string a;
  char c;
  int s;
  cin >> verb;
  cin >> object;
  s = object.size();
  c = object[s-1];
  switch(c) {
    case 'e':
      a = "la";
      break;
    case 's':
      a = "les";
      break;
    default:
      a = "le";
      break;
  }
  cout << verb << "-tu " << a << " " << object << " ?\n";
}
