#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans;
    int numStart; // t-shirts at start
    int numEvents;
    int numDays;
    int day;
    vector<int> events;
    for(int ii=1; ii<=10; ii++) {
        cin >> numStart >> numEvents >> numDays;
        events.clear();
        events.resize(numDays+1);
        for(int i=0; i<numEvents; i++) {
            cin >> day;
            events[day]++; // one more t-shirt that day
        }
        // processing >>
        int clean = numStart;
        int total = numStart;
        ans = 0; // number of times he needs to wash the shirts
        for(int d=1; d<=numDays; d++) {
            if(clean ==0) {
                clean = total;
                ans++;
            }
            clean += events[d];
            total += events[d];
            clean--;
        }
        cout << ans << endl;
    }
        
}
