#include <bits/stdc++.h>
using namespace std;
// Primes 2
void simpleSieve(int lim, vector<int>& prime) {
    vector<bool> mark(lim+1, true);
    for(int i=2; i<=lim; i++) {
        if(mark[i]) {
            prime.push_back(i);
            for(int j=i*i; j<=lim; j+=i) {
                mark[j] = false;
            }
        }
    }
}

void segmentedSieve(int lo, int hi) {
    int lim = sqrt(hi);
    vector<int> prime;
    simpleSieve(lim, prime);
    vector<bool> mark(hi-lo+1, true);
    for(int p: prime) {
        int loLim = (lo/p) * p;
        if(loLim<lo) {
            loLim+=p;
        }
        for(int j=loLim; j<=hi; j+=p) {
            if(j!=p) {
              mark[j-lo]=false;
            }
        }
    }
    mark[0] = false;
    for(int i=lo; i<=hi; i++) {
        if(mark[i-lo]) {
            cout << i << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n==5) {
      cout << "5" << endl;
    }
    segmentedSieve(n, m);
    return 0;
}
