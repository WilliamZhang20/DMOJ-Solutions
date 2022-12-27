#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> s) {
    if (s.empty())
        return;  
    int x = s.top();
    s.pop();
    printStack(s);
    cout << x << " ";
    s.push(x);
    cout << endl;
}

char moveCars(stack<int> ingr, int n) {
  stack<int> branch;
  int i=1;
  int temp;
  while(true) {
    // printStack(ingr);
    if(ingr.size()>0 && ingr.top()==i) { // next car in mountain matches number
      ingr.pop(); // Slide from mountain to lake
      i++;
    } 
    else if(branch.size()>0 && branch.top()==i) {
      branch.pop(); // Slide from branch to lake
      i++;
    }
    else if((ingr.size()>0 && ingr.top()!=i) || (branch.size()>0 && branch.top()!=i)) {
      if(ingr.size()>0) {
        temp = ingr.top();
        branch.push(temp); // Slide to branch
        ingr.pop();
      } else {
        return 'N';
      }
    }
    else {
      return 'Y';
    }
  }
}

int main() {
  int t;
  int n;
  int input;
  cin >> t;
  char output[t];
  stack<int> cars;
  for(int i=0; i<t; i++) {
    cin >> n;
    for(int j=0; j<n; j++) {
      cin >> input;
      cars.push(input);
    }
    output[i]=moveCars(cars, n);
    cars = {};
  }
  for(auto a: output) {
    cout << a << endl;
  }
}
