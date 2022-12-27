#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r1, g1, b1;
    cin >> r1 >> g1 >> b1;
    int r2, g2, b2;
    cin >> r2 >> g2 >> b2;
    if(int(sqrt(r1))==int(sqrt(r2)) && int(sqrt(g1))==int(sqrt(g2)) && int(sqrt(b1))==int(sqrt(b2))) {
        cout << "Dull\n";
    }
    else {
        cout << "Colourful\n";
    }
}
