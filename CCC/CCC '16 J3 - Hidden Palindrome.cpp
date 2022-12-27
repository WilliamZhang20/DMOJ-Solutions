#include <bits/stdc++.h>
// Manacher's Algorithm
using namespace std;

string longestPalindrome(string mainString) {
   int n = mainString.size();
   if(n == 0)
      return "";
   n = 2*n + 1; 
   int longPal[n]; 
   longPal[0] = 0; longPal[1] = 1;
   int centerIndex = 1;
   int rightIndex = 2;
   int right = 0, left;
   int maxPalLength = 0, maxCenterIndex = 0;
   int start = -1, end = -1, diff = -1;

   for (right = 2; right < n; right++) {
      left  = 2*centerIndex-right; 
      longPal[right] = 0;
      diff = rightIndex - right;

      if(diff > 0)
         longPal[right] = min(longPal[left], diff);
      while ( ((right + longPal[right]) < n && (right - longPal[right]) > 0) &&
         ( ((right + longPal[right] + 1) % 2 == 0) ||
         (mainString[(right + longPal[right] + 1)/2] == mainString[(right - longPal[right] - 1)/2] ))) {
         longPal[right]++;
      }

      if(longPal[right] > maxPalLength) {   
         maxPalLength = longPal[right];
         maxCenterIndex = right;
      }

      if (right + longPal[right] > rightIndex) {
         centerIndex = right;
         rightIndex = right + longPal[right];
      }
   }

   start = (maxCenterIndex - maxPalLength)/2;
   end = start + maxPalLength - 1;
   string palindrome;

   for(int i=start; i<=end; i++)
      palindrome += mainString[i];
      return palindrome;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string main;
  string palindrome;
  getline(cin, main);
  palindrome = longestPalindrome(main);
  cout << palindrome.length() << endl;
}
