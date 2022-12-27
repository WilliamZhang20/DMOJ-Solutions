#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
// Lelei and Dragon Scales

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    int w, h, n;
    scan(w); scan(h); scan(n);
    int psa[251][251]; // MAXH = MAXW = 250
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            scan(psa[i][j]);
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    int length = n;
    int res = 0;
    while(length) {
        int width = min(w, n/length);
        for(int i=1; i + length <= h + 1; i++) {
            for(int j=1; j + width <= w + 1; j++) {
                int temp = psa[i+length-1][j+width-1] - psa[i+length-1][j-1] - psa[i-1][j+width-1] + psa[i-1][j-1];
                if(temp>res) {
                    res = temp;
                }
            }
        }
        length--;
    }
    cout << res << "\n";
}
