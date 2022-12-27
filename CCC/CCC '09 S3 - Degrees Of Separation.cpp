#include <bits/stdc++.h>
#define INF 99999

using namespace std;

int friends[50][50];

void edge(int a, int b) {
	friends[a][b] = 1;
	friends[b][a] = 1;
}

void remove(int a, int b) {
	friends[a][b] = 0;
	friends[b][a] = 0;
}

void init() {
	edge(1, 6);
	edge(2, 6);
	edge(3, 6);
	edge(4, 6);
	edge(5, 6); 
	edge(3, 5);
	edge(3, 4);
	edge(4, 5);
	edge(6, 7);
	edge(7, 8); 
	edge(8, 9);
	edge(9, 12);
	edge(9, 10);
	edge(10, 11); 
	edge(11, 12);
	edge(3, 15);
	edge(12, 13);
	edge(13, 15); 
	edge(13, 14);
	edge(16, 18);
	edge(16, 17);
	edge(17, 18);
}

int friendsOfFriends(int a) {
	int second[50][50];
	int count=0;
	for(int i=0; i<50; i++) {
		for(int j=0; j<50; j++) {
			second[i][j] = friends[i][j];
		}
	}
	for(int i=0; i<50; i++) {
		if(second[a][i]==1) {
			for(int j=0; j<50; j++) {
				if(second[i][j]==1 && j!=a && second[a][j]==0) {
					second[a][j]=2;
				}
			}
		}
	}
	for(int i=0; i<50; i++) {
		if(second[a][i]==2) {
			count++;
		}
	}
	return count;
}

int degsOfSeparation(int a, int b) {
	// Floyd - Warshall Algorithm
	int distance[50][50];
	for(int i=0; i<50; i++) {
		for(int j=0; j<50; j++) {
			if(friends[i][j]==1) {
				distance[i][j]=friends[i][j];
			} else {
				distance[i][j] = INF;
			}
		}
	}
	for(int k=0; k<50; k++) {
		for(int i=0; i<50; i++) {
			for(int j=0; j<50; j++) {
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
	return distance[a][b];
}

int main() {
	for(int i=0; i<50; i++) {
		for(int j=0; j<50; j++) {
			friends[i][j]=0;
		}
	}
	init();
	char cmd;
	int x, y;
	cin >> cmd;
	while(cmd!='q') {
		if(cmd=='i') {
			cin >> x >> y;
			edge(x, y);
		}
		else if(cmd=='d') {
			cin >> x >> y;
			remove(x, y);
		}
		else if(cmd=='n') {
			cin >> x;
			int c = 0;
			for(int i=0; i<50; i++) {
				if(friends[x][i]) {
					c++;
				}
			}
			cout << c << endl;
		}
		else if(cmd=='f') {
			cin >> x;
			cout << friendsOfFriends(x) << endl;
		} 
		else if(cmd=='s') {
			cin >> x >> y;
			int val = degsOfSeparation(x, y);
			if(val!=INF) {
				cout << val << endl;
			} else {
				cout << "Not connected" << endl;
			}
		}
		cin >> cmd;
	}
}
