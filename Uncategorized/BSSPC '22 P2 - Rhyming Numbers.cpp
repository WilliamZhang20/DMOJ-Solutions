#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
/*#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;*/
#define sz(x) (int)x.size()
using namespace std;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string a, b;
		cin >> a >> b;
		if(sz(a)>=3) {
			a = a.substr(sz(a)-2);
		} 
		if(sz(b)>=3) {
			b = b.substr(sz(b)-2);
		}
		if(((a=="11" && b[sz(b)-1]=='7') || (a[sz(a)-1]=='7' && b=="11")) && a != "17" && b != "17") {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
