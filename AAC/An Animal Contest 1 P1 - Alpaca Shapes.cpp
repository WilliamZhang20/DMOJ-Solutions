#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll s, r;
    cin >> s >> r;
    ll a1 = s * s;
    ll a2 = 3.14 * r * r;
    if(a1>a2) {
        cout << "SQUARE\n";
    } else {
        cout << "CIRCLE\n";
    }
}
