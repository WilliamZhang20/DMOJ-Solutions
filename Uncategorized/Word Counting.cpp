#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    // function: t(p(i)) = w(i) / p(i) + p(i) 
    // num. of words constant, num. of pages variable, equal words per page
	// derivative of function: t'(i) = -w(i)/(p(i))^2 + 1
    // p(i) = sqrt(w(i)) -> the key!
    int n, q;
    cin >> n >> q;
    vector<double> p;
    unordered_map<double, int> store_idx;
    for(int i=1; i<=n; i++) {
        int val;
        cin >> val;
        if(!store_idx.count(val)) {
            p.push_back(val);
            store_idx[val] = i;
        }
    }
    sort(p.begin(), p.end());
    for(int i=0; i<q; i++) {
        int w;
        cin >> w; // words in each BOOK
        // applying optimization, q times for each book
        double res = sqrt(w);
        auto hi_lim = upper_bound(p.begin(), p.end(), res);
        auto lo_lim = hi_lim - 1;
        double lo_val = w/(*lo_lim) + *lo_lim;
        double hi_val = w/(*hi_lim) + *hi_lim;
        //cout << "(" << lo_val << "_" << hi_val << ") ";
        // comparing buttons
        if(hi_lim==p.begin()) { // highest button close is first
            cout << store_idx[*hi_lim] << " ";
            continue;
        } 
        else if(hi_lim==p.end()) { // highest button is beyond last
            cout << store_idx[p[n-1]] << " ";
            continue;
        } 
        else {
            if(lo_val < hi_val || (lo_val == hi_val && store_idx[*lo_lim] < store_idx[*hi_lim])) {
                cout << store_idx[*lo_lim] << " ";
            } else {
                cout << store_idx[*hi_lim] << " ";
            }
        }
    }
    cout << "\n";
}
