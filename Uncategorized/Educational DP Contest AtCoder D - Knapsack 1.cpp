#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll max(ll a, ll b) { return (a>b) ? a : b; }

ll knapsack(int w, ll wt[], ll val[], int n) {
    ll dp[w+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<n+1; i++) {
        for(int j = w; j>=0; j--) {
            if(wt[i-1]<=j) {
                dp[j] = max(dp[j], dp[j-wt[i-1]]+val[i-1]);
            } 
        }
    }
    return dp[w];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    int w; // capacity
    ll *val, *wt;
    cin >> n >> w;
    val = new ll[n];
    wt = new ll[n];
    for(int i=0; i<n; i++) {
        cin >> wt[i] >> val[i];
    }
    cout << knapsack(w, wt, val, n) << endl;
    return 0;
}
