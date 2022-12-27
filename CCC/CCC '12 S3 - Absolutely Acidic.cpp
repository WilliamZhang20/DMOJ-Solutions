#include <bits/stdc++.h>
using namespace std;

int absDiff(int x, int y) {
  if(x>y) {
    return x-y;
  }
  return y-x;
}

int main() {
  int n;
  int input;
  cin >> n;
  vector<int> occur(2000001, 0);
  vector<int> freq(2000001, 0);
  int counter=0;
  for(int i=1; i<=n; i++) {
    cin >> input;
    if(freq[input]==0) {
      occur[counter] = input;
      freq[input]++;
      counter++;
    } else {
      freq[input]++;
    }
  }
  int largestFreq = 0;
  for(int i=0; i<counter; i++) {
    if(freq[occur[i]]>largestFreq) {
      largestFreq = freq[occur[i]];
    }
  }
  vector<int> firstLargest; // readings with largest frequency
  for(int i=0; i<counter; i++) {
    if(freq[occur[i]]==largestFreq) {
      firstLargest.push_back(occur[i]);
    }
  }
  int largestDiff;
  if(firstLargest.size()>1) { // compute largest absDiff between readings of highest frequency
    largestDiff=0;
    for(int i=0; i<firstLargest.size()-1; i++) {
      for(int ii=0; ii<firstLargest.size(); ii++) {
        if(absDiff(firstLargest[i], firstLargest[ii])>largestDiff) {
          largestDiff = absDiff(firstLargest[i], firstLargest[ii]);
        }
      }
    }
    cout << largestDiff << endl;
  } else {
    if(freq[firstLargest[0]]==n) {
      cout << "0" << endl;
    } else {
      int second=0;
      for(int i=0; i<counter; i++) {
        if(freq[occur[i]]>second && occur[i]!=firstLargest[0]) {
          second = freq[occur[i]]; // finding second highest frequency
        }
      }
      vector<int> secondLargest; // readings with second largest frequency
      for(int i=0; i<counter; i++) {
        if(freq[occur[i]]==second) {
          secondLargest.push_back(occur[i]);
        }
      }
      if(secondLargest.size()==1) {
        cout << absDiff(firstLargest[0], secondLargest[0]) << endl;
      } else {
        int largestDiff2=0;
        for(int i=0; i<secondLargest.size(); i++) {
          if(absDiff(firstLargest[0], secondLargest[i])>largestDiff2) {
            largestDiff2 = absDiff(firstLargest[0], secondLargest[i]);
          }
        }
        cout << largestDiff2 << endl;
      }
    }
  }
  return 0;
}
