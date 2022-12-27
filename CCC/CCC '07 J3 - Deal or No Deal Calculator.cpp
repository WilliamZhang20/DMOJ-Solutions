#include <bits/stdc++.h>

using namespace std;

double averageMoney(int cases[], int n) {
    int sum = 0;
    double average;
    for(int i=0; i<n; i++) {
        switch (cases[i]) {
            case 1: cases[i]=100;
                    break;
            case 2: cases[i]=500;
                    break;
            case 3: cases[i]=1000;
                    break;
            case 4: cases[i]=5000;
                    break;
            case 5: cases[i]=10000;
                    break;
            case 6: cases[i]=25000;
                    break;
            case 7: cases[i]=50000;
                    break;
            case 8: cases[i]=100000;
                    break;
            case 9: cases[i]=500000;
                    break;
            case 10: cases[i]=1000000;
                    break;
            default: 
                    break;
         }
         sum+=cases[i];
    }
    sum=1691600-sum; //since we are finding the avg of remaining suitcases, so that is the sum of all the money in all the cases available minus what is eliminated.
    average=1.0*(sum/(10-n));
    return average;
}

int main() {
    int n; //how many cases have been opened so far
    int offer; 
    double average;
    cin >> n;
    int s[n];
    for(int i=0; i<n; i++) {
        cin >> s[i]; //value of each case
    }
    cin >> offer; //banker's offer
    average = averageMoney(s, n); // calculate average using function
    if(offer>average) {
        cout << "deal\n";
    } else {
        cout << "no deal\n";
    }
    return 0;
}
