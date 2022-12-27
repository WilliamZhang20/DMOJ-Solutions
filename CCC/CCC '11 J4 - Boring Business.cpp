#include <bits/stdc++.h>

using namespace std;

class Bore {
  private:
    int x=-1;
    int y=-5;
    bool safe = true;
    // Use map of pairs, since a bool is connected to each pair of coordinates
    map<pair<int, int>, bool> points;
  public:
    Bore() {
      // Constructor function
      points[make_pair(0, -1)] = true;
      points[make_pair(0, -2)] = true;
      points[make_pair(0, -3)] = true;
      points[make_pair(1, -3)] = true;
      points[make_pair(2, -3)] = true;
      points[make_pair(3, -3)] = true;
      points[make_pair(3, -4)] = true;
      points[make_pair(3, -5)] = true;
      points[make_pair(4, -5)] = true;
      points[make_pair(5, -5)] = true;
      points[make_pair(5, -4)] = true;
      points[make_pair(5, -3)] = true;
      points[make_pair(6, -3)] = true;
      points[make_pair(7, -3)] = true;
      points[make_pair(7, -4)] = true;
      points[make_pair(7, -5)] = true;
      points[make_pair(7, -6)] = true;
      points[make_pair(7, -7)] = true;
      points[make_pair(6, -7)] = true;
      points[make_pair(5, -7)] = true;
      points[make_pair(4, -7)] = true;
      points[make_pair(3, -7)] = true;
      points[make_pair(2, -7)] = true;
      points[make_pair(1, -7)] = true;
      points[make_pair(0, -7)] = true;
      points[make_pair(-1, -7)] = true;
      points[make_pair(-1, -6)] = true;
      points[make_pair(-1, -5)] = true;
    }
    void drill(char d, int len) {
      switch(d) {
        case 'd':
          for(int i=0; i<len; i++) {
            y--;
            if(points[make_pair(x, y)]==true) {
              safe = false;
            }
            points[make_pair(x, y)] = true;
          }
          cout << x << " " << y;
          if(safe) {
            cout << " safe\n";
          } else {
            cout << " DANGER\n";
          }
          break; 
        case 'u':
          for(int i=0; i<len; i++) {
            y++;
            if(points[make_pair(x, y)]==true) {
              safe = false;
            }
            points[make_pair(x, y)] = true;
          }
          cout << x << " " << y;
          if(safe) {
            cout << " safe\n";
          } else {
            cout << " DANGER\n";
          }
          break; 
        case 'l':
          for(int i=0; i<len; i++) {
            x--;
            if(points[make_pair(x, y)]==true) {
              safe = false;
            }
            points[make_pair(x, y)] = true;
          }
          cout << x << " " << y;
          if(safe) {
            cout << " safe\n";
          } else {
            cout << " DANGER\n";
          }
          break; 
        case 'r':
          for(int i=0; i<len; i++) {
            x++;
            if(points[make_pair(x, y)]==true) {
              safe = false;
            }
            points[make_pair(x, y)] = true;
          }
          cout << x << " " << y;
          if(safe) {
            cout << " safe\n";
          } else {
            cout << " DANGER\n";
          }
          break; 
        default:
          break;
      }
    }
    bool getStatus() {
      if(safe) {
        return true;
      }
      return false;
    }
};

int main() {
  Bore b;
  char a;
  int len;
  while(true) {
    cin >> a >> len;
    b.drill(a, len);
    if(a=='q') {
      break;
    } else if(b.getStatus()==false) {
      break;
    }
  }
}
