#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int SIZE = 8;
const int n = 7;

vector<int> adj[SIZE];
set<int> pq;
bool visited[SIZE];
vector<int> ans;

void addEdge(int a, int b) {
    adj[a].pb(b);
}

int in_count(int v) {
    int count = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<adj[i].size(); j++) {
            if(adj[i][j] == v) {
                count++;
            }
        }
    }
    return count;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	addEdge(1, 7);
    addEdge(1, 4);
    addEdge(2, 1);
    addEdge(3, 4);
    addEdge(3, 5);
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a==0 && b==0) {
            break;
        }
        addEdge(a, b);
    }
    for(int i=1; i<=n; i++) {
        if(in_count(i) == 0) {
            pq.insert(i);
        }
    }
    while(!pq.empty()) {
        int curr = *pq.begin();
        pq.erase(pq.begin());
        ans.pb(curr);
        for(int i=0; i<adj[curr].size(); i++) {
            if(in_count(adj[curr][i])==1) {
                pq.insert(adj[curr][i]);
            }
        }
        adj[curr].clear();
    }
    for(int i=1; i<=7; i++) {
        if(in_count(i)>0) {
            cout << "Cannot complete these tasks. Going to bed.\n";
            return 0;
        }
    }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if(i<ans.size()-1) {
            cout << " ";
        } else {
            cout << '\n';
        }
    } 
}
