#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int sx, sy, sz;
	int tx, ty, tz;
	int xDist, yDist, zDist;
	int dist, newX;
	double closest;
	char dir;
	int temp;
	cin >> sx >> sy >> sz;
	cin >> tx >> ty >> tz;
	xDist = tx-sx;
	yDist = ty-sy;
	zDist = tz-sz;
	closest = pow(xDist, 2) + pow(yDist, 2) + pow(zDist, 2);
	do {
		cin >> dist >> dir;
		newX = xDist-dist;
		if(newX*xDist<0) {
			// If the turtle passed the planet on the x plane
			closest = min(closest, pow(yDist, 2) + pow(zDist, 2));
		} else {
			// If the turtle came closer to the planet
			closest = min(closest, pow(newX, 2) + pow(yDist, 2) + pow(zDist, 2));
		}
		xDist = newX;
		temp = xDist;
		if(dir=='L') {
			// Turning left
			xDist = yDist;
			yDist = -1*temp;
		} else if(dir=='R') {
			// Turning right
			xDist = -yDist;
			yDist = temp;
		} else if(dir=='U') {
			// Going up
			xDist = zDist;
			zDist = -1*temp;
		} else {
			// Going down
			xDist = -1*zDist;
			zDist = temp;
		}
	} while(dir!='E');
	cout << fixed << setprecision(2) << sqrt(closest) << endl;
}
