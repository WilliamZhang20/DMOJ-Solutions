#include <iostream>
using namespace std;

int main()
{    
    int x, n, quotient, remainder;
    cin >> x >> n;

    quotient = x / n;
    remainder = x % n;

    cout << quotient <<" "<< remainder;
    
    return 0;
}
