#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
#define ps_b push_back
#define ps_f push_front
#define po_b pop_back
#define po_f pop_front
using namespace std;

bool solve(deque<int> dq, int t) {
    deque<int> finished;
    if(t==0) {
        finished.ps_b(dq.front());
        dq.po_f();
    } 
    else if(t==1) {
        finished.ps_b(dq.back());
        dq.po_b();
    }
    while(!dq.empty()) {
        if(dq.front()==finished.back() + 1) {
            finished.ps_b(dq.front());
            dq.po_f();
        } 
        else if(dq.front()==finished.front()-1) {
            finished.ps_f(dq.front());
            dq.po_f();
        } 
        else if(dq.back()==finished.back()+1) {
            finished.ps_b(dq.back());
            dq.po_b();
        } 
        else if(dq.back()==finished.front()-1) {
            finished.ps_f(dq.back());
            dq.po_b();
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        deque<int> dq;
        for(int j=0; j<n; j++) {
            int v;
            cin >> v;
            dq.ps_b(v);
        }
        if(solve(dq, 0)) {
            cout << "yes\n"; 
        } else {
            if(solve(dq, 1)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

}
