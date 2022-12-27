#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
// Foxhole

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    int t; // num. of test cases;
    cin >> t;   
    while(t--) {
        int h, w, n; // grid is h deep, w across, n actions
        cin >> h >> w >> n;
        char grid[h+1][w];
        for(int i=1; i<=h; i++) {
            for(int j=0; j<w; j++) {
                cin >> grid[i][j];
            }
        }
        int treasure = 0;
        pair<int, int> curr = {0, 0};
        for(int i=0; i<n; i++) {
            char act;
            // cout << "input\n";
            cin >> act;
            if(act=='L') {
                if(curr.S<1 || (curr.S>=1 && grid[curr.F][curr.S-1]=='S')) {
                    // cout << "stop1a\n";
                    continue;
                } else {
                    curr.S--;
                    // cout << "stop2a\n";
                    if(grid[curr.F][curr.S]=='T') {
                        treasure++;
                        grid[curr.F][curr.S] = 'D'; // reset to dirt
                        // cout << "stop3a\n";
                    }
                    while(curr.F<=h && grid[curr.F+1][curr.S]=='E') {
                        // cout << "stop4a\n";
                        curr.F++;
                    }
                } 
            } else if(act=='R') {
                if(curr.S==w-1 || (curr.S<w-1 && grid[curr.F][curr.S+1]=='S')) {
                    // cout << "Stop1b\n";
                    continue;
                } else {
                    curr.S++;
                    // cout << "stop4b\n";
                    if(grid[curr.F][curr.S]=='T') {
                        // cout << "stop2b\n";
                        treasure++;
                        grid[curr.F][curr.S] = 'D'; // reset to dirt
                    }
                    while(curr.F<=h && grid[curr.F+1][curr.S]=='E') {
                        // cout << "stop3b\n";
                        curr.F++;
                    }
                }
            } else if(act=='D') {
                if(curr.F==h || (curr.F<=h-1 && grid[curr.F+1][curr.S]=='S')) {
                    // cout << "stop1c\n";
                    continue;
                } else {
                    curr.F++;
                    // cout << "stop2c\n";
                    if(grid[curr.F][curr.S]=='T') {
                        // cout << "stop4c\n";
                        treasure++;
                        grid[curr.F][curr.S] = 'D'; // reset to dirt
                    }
                    while(curr.F<=h && grid[curr.F+1][curr.S]=='E') {
                        // cout << "stop3c\n";
                        curr.F++;
                    }
                }
            }
        }
        cout << treasure << "\n";
    }
}
