#include <iostream>

using namespace std;

bool check(int **a, int s) {
  for(int i=0; i<s; i++) {
    for(int j = 0; j<s-1; j++) {
      if(i<s-1 && (a[i][j]>a[i][j+1] || a[i][j]>a[i+1][j])) {
        return false;
      } else if(i==s-1 && a[i][j]>a[i][j+1]) {
        return false;
      }
    }
  }
  return true;
}

int** rotateOnce(int **a, int s) {
  int **next;
  next = new int*[s];
  for(int i=0; i<s; i++) {
    next[i] = new int[s];
    for(int j = 0; j<s; j++) {
      next[i][j] = a[j][s-1-i];
    }
  }
  return next;
}

void printArray(int **arr, int s) {
  for(int i=0; i<s; i++) {
    for(int j=0; j<s; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int **a;
  int **next;
  cin >> n;
  a = new int*[n];
  for(int i=0; i<n; i++) {
    a[i] = new int[n];
    for(int j=0; j<n; j++) {
      cin >> a[i][j];
    }
  }
  if(check(a, n)) {
    printArray(a, n); // 0 degrees
  } else {
    // 90 degrees
    next = rotateOnce(a, n); 
    if(check(next, n)) {
      printArray(next, n);
    } else {
      // 180 degrees
      next = rotateOnce(next, n); 
      if(check(next, n)) {
        printArray(next, n);
      } else {
        // 270 degrees
        next = rotateOnce(next, n); 
        printArray(next, n);
      }
    }
  }
}
