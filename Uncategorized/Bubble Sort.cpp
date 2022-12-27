#include <iostream>

using namespace std;

void printArr(int a[], int n) {
  for(int i=0; i<n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void bubbleSortArr(int a[], int n) {
  int temp;
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-1-i; j++) {
      if(a[j]>a[j+1]) {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        printArr(a, n);
      }
    }
  }
}

int main() {
  int sz;
  cin >> sz;
  int arr[sz];
  for(int i=0; i<sz; i++) {
    cin >> arr[i];
  }
  printArr(arr, sz);
  bubbleSortArr(arr, sz);
}
