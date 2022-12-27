#include <iostream>

using namespace std;

int main() {
  int x, a, b, c;
  int count = 0;
  cin >> x >> a >> b >> c;
  while(x!=0) {
    x--;
    count++;
    a++;
    if(a==35) {
      a=0;
      x+=30;
    }
    if(x==0) {
      break;
    }
    x--;
    count++;
    b++;
    if(b==100) {
      b=0;
      x+=60;
    }
    if(x==0) {
      break;
    }
    x--;
    count++;
    c++;
    if(c==10) {
      c=0;
      x+=9;
    }
  }
  cout << "Martha plays " << count << " times before going broke.\n";
}
