#include <bits/stdc++.h>

using namespace std;

class Box {
  public:
    long long int getVolume() const {
      return l*w*h;
    }
    long long int getHeight() const {
      return h;
    }
    long long int getLength() const {
      return l;
    }
    long long int getWidth() const {
      return w;
    }
    void putData(long long int l, long long int w, long long int h) {
      this->l=l;
      this->w=w;
      this->h=h;
    }
    Box() {
      l = 0;
      w = 0;
      h = 0;
    }
  private:
    long long int l, w, h;
};

void sortBoxArr(Box b[], int n) {
  Box temp;
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-1-i; j++) {
      if(b[j].getVolume()>b[j+1].getVolume()) {
        temp = b[j];
        b[j] = b[j+1];
        b[j+1] = temp;
      }
    }
  }
}

void sortNums(long long int *a, long long int *b, long long int *c) {
  long long int temp;
  long long int arr[3];
  arr[0] = *a;
  arr[1] = *b;
  arr[2] = *c;
  for(int i=0; i<3-1; i++) {
    for(int j=0; j<3-1-i; j++) {
      if(arr[j]>arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  *a = arr[0];
  *b = arr[1];
  *c = arr[2];
}

int main() {
  int numItems;
  int numBoxes;
  cin >> numBoxes;
  long long int length, width, height;
  Box b[numBoxes];
  for(int i=0; i<numBoxes; i++) {
    cin >> length >> width >> height;
    sortNums(&length, &width, &height);
    b[i].putData(length, width, height);
  }
  sortBoxArr(b, numBoxes);
  cin >> numItems;
  for(int i=0; i<numItems; i++) {
    cin >> length >> width >> height;
    sortNums(&length, &width, &height);
    // NOTE: sort l, w, h in EACH BOX to simulate trying to fit the item in the box at different angles.
    for(int j=0; j<numBoxes; j++) {
      if(b[j].getLength()>=length && b[j].getWidth()>=width && b[j].getHeight()>=height) {
        cout << b[j].getVolume() << endl;
        break;
      } else if(j==numBoxes-1) {
        cout << "Item does not fit." << endl;
      }
    }
  } 
}
