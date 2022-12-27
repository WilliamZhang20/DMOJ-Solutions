// Merge Sort Code
#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int left[n1], right[n2];

  for (int i = 0; i < n1; i++)
    left[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    right[j] = a[q + 1 + j];
  int i, j, k; // create pointers
  i=0; 
  j=0; 
  k=p;
  while(i<n1 && j<n2) { // pick up larger element to put into next array, A[p....r]
    if (left[i] <= right[j]) {
      a[k] = left[i];
      i++;
    } else {
      a[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    a[k] = left[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = right[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void printArray(int a[], int sz) {
  for (int i = 0; i < sz; i++)
    cout << a[i] << "\n";
}

int main() {
  int s;
  //cout << "Please input size of the array: ";
  cin >> s;
  int a[s];
  //cout << "Please input elements of array: \n";
  for(int i=0; i<s; i++) {
    cin >> a[i];
  }
  mergeSort(a, 0, s-1);
  //cout << "Sorted array:\n";
  printArray(a, s);
  return 0;
}
