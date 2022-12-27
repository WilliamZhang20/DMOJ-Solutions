#include <iostream>

using namespace std;

int main() {
  int b;
  int p;
  char v;
  char type = 'O';
  cin >> b >> p >> v;
  if(v=='Y') {
    if(b/(5*p)>0) {
      type = 'B';
    } else if(b/(2*p)>0) {
      type = 'D';
    }
  } else if(v=='N') {
    if(b/(5*p)>0) {
      type = 'A';
    } else if(b/(2*p)>0) {
      type = 'C';
    }
  }
  type!='O'? cout << type << endl: cout << "NO PIZZA\n";
}
