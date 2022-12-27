#include <bits/stdc++.h>

using namespace std;

class Computer {
  public:
    int getVal() {
      int num = 2*ram + 3*cpuSpd + driveSpace;
      return num;
    }
    void setR(int a) {
      this->ram = a;
    }
    void setC(int b) {
      this->cpuSpd = b;
    }
    void setD(int c) {
      this->driveSpace = c;
    }
    void setName(string s) {
      this->name = s;
    }
    string getName() const {
      return name;
    }
  private:
    string name;
    int ram;
    int cpuSpd;
    int driveSpace;
};

void swap(Computer *a, Computer *b) {
  Computer temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(Computer lst[], int s) {
  int equal;
  for(int i=0; i<s-1; ++i) {
    for(int j=0; j<s-i-1; ++j) {
      if(lst[j].getVal()>lst[j+1].getVal()) {
        swap(&lst[j], &lst[j+1]);
      } else if(lst[j].getVal()==lst[j+1].getVal()) {
        equal = lst[j].getName().compare(lst[j+1].getName());
        if(equal<0) {
          swap(&lst[j], &lst[j+1]);
        }
      }
    }
  }
}

int main() {
  int n;
  string name;
  int a, b, c;
  cin >> n;
  Computer list[n];
  for(int i=0; i<n; i++) {
    cin >> name >> a >> b >> c;
    list[i].setName(name);
    list[i].setR(a);
    list[i].setC(b);
    list[i].setD(c);
    if(n==1) {
      break;
    }
  }
  if(n>0) {
    bubbleSort(list, n);
    cout << list[n-1].getName() << endl;
    if(n>=2)
      cout << list[n-2].getName() << endl;
  }
  return 0;
}
