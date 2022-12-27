#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // number of days in each month
  int m, d;
  int numDays = 0;
  cin >> d >> m;
  for(int i=0; i<m-1; i++) {
    numDays+=days[i];
  }
  numDays+=d-1;
  switch(numDays%7) {
    case 0:
      cout << "Thursday\n";
      break;
    case 1:
      cout << "Friday\n";
      break;
    case 2:
      cout << "Saturday\n";
      break;
    case 3:
      cout << "Sunday\n";
      break;
    case 4:
      cout << "Monday\n";
      break;
    case 5:
      cout << "Tuesday\n";
      break;
    case 6:
      cout << "Wednesday\n";
      break;
    default:  
      break;
  }
}
