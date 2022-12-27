#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
	scan(n);
	int sum = 0;
    for(int i=0; i<n; i++) {
		int x;
		scan(x);
		sum += x;
		cout << sum << "\n";
	}
}
