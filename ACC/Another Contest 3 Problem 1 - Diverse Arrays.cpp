#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAX_VAL = 1e6 + 1;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    ll a[MAX_VAL];
    int freq[MAX_VAL];
    cin >> n >> k;
    ll total = (n*n + n) / 2; // indirect method -> all situations - invalid situations
    ll sz = 0;
    ll y = 0; // first element of the subarray
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(freq[a[i]]==0) {
            sz++;
        }
        freq[a[i]]++;
        while(sz>=k) { // at least k distinct integers
            freq[a[y]]--;
            if(!freq[a[y]]) {
                sz--;
            }
            y++;
        }
        total -= i-y; // size of subarray
    }
    cout << total - n << "\n";  
}
