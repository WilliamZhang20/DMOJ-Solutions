#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    int count = 0;
    cin >> n;
    char a[n], b[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    for(int i=0; i<n; i++) {
        if(a[i]=='C' && b[i]=='C') {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
