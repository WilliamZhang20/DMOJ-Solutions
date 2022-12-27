#include <iostream>

using namespace std;

int main() {
  int b, s, dr, de;
  int calorieCount=0;
  cin >> b >> s >> dr >> de;
  switch(b) {
    case 1:
      calorieCount+=461;
      break;
    case 2:
      calorieCount+=431;
      break;
    case 3:
      calorieCount+=420;
      break;
    case 4:
      calorieCount+=0;
      break;
    default:
      cout << "Wrong Number Entered";
      break;
  }
  switch(s) {
    case 1:
      calorieCount+=100;
      break;
    case 2:
      calorieCount+=57;
      break;
    case 3:
      calorieCount+=70;
      break;
    case 4:
      calorieCount+=0;
      break;
    default:
      cout << "Wrong Number Entered";
      break;
  }
  switch(dr) {
    case 1:
      calorieCount+=130;
      break;
    case 2:
      calorieCount+=160;
      break;
    case 3:
      calorieCount+=118;
      break;
    case 4:
      calorieCount+=0;
      break;
    default:
      cout << "Wrong Number Entered";
      break;
  }
  switch(de) {
    case 1:
      calorieCount+=167;
      break;
    case 2:
      calorieCount+=266;
      break;
    case 3:
      calorieCount+=75;
      break;
    case 4:
      calorieCount+=0;
      break;
    default:
      cout << "Wrong Number Entered";
      break;
  }
  cout << "Your total Calorie count is " << calorieCount << ".\n";
}
