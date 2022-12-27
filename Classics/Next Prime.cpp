#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int main() {
    int min; 
    cin >> min;
    for(int i=min; i<INT_MAX; i++) {
        if(isPrime(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
