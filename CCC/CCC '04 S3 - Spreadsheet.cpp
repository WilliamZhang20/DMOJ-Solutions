#include <bits/stdc++.h>

using namespace std;

string cells[11][10];
int cell_values[11][10] = {0};
bool calculated[11][10];

int getValue(int, int, vector<vector<bool>>);
int convertToNumber(char);

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	for(int i=1; i<=10; i++) {
		for(int j=1; j<=9; j++) {
			cin >> cells[i][j];
		}
	}
	for(int i=1; i<=10; i++) {
		for(int j=1; j<=9; j++) {
			if(!calculated[i][j]) {
				vector<vector<bool>> visited(11, vector<bool>(10));
				cell_values[i][j]=getValue(i, j, visited);
			} 
		}
	}
	for(int i=1; i<=10; i++) {
		for(int j=1; j<=9; j++) {
			if(cell_values[i][j]==-1) {
				cout << "* ";
			} else {
				cout << cell_values[i][j] << " ";
			}
		} cout << endl;
	}
	return 0;
}

int letter_to_number(char ch) {
	switch(ch) {
		case 'A': 
			return 1;
		case 'B':
			return 2;
		case 'C':
			return 3;
		case 'D':
			return 4;
		case 'E':
			return 5;
		case 'F':
			return 6;
		case 'G':
			return 7;
		case 'H':
			return 8;
		case 'I':
			return 9;
		case 'J':
			return 10;
		default:
			return 0;
	}
}

int getValue(int row, int col, vector<vector<bool>> visited) {
	//cout << "In the function at " << row << " " << col << endl;
	if(calculated[row][col]) {
		//cout << "stop1 " << cell_values[row][col] << endl;
		return cell_values[row][col];
	}
	if(cells[row][col].find('+')==-1 && cells[row][col][0]-'0'<=9) { // a numerical value (first value is num.)
		int curr_pow_10 = 0;
		for(int i=cells[row][col].length()-1; i>=0; i--)  		{
			cell_values[row][col]+=pow(10, curr_pow_10) * (cells[row][col][i]-'0');
			curr_pow_10++;
		}
		calculated[row][col]=true;
		//cout << "stop2 " << cell_values[row][col] << endl;
		return cell_values[row][col];
	}
	if(visited[row][col]) {
		return -1;
	}
	vector<vector<bool>> visited_copy = visited;
	visited_copy[row][col]=true;
	for(int i=0; i<=cells[row][col].length()-2; i+=3) {
		int sub_value;
		sub_value = getValue(letter_to_number(cells[row][col][i]), cells[row][col][i+1]-'0', visited_copy);
		//cout << "Received " << sub_value << endl;
		if(sub_value==-1) {
			return -1;
		} else {
			cell_values[row][col]+=sub_value;
		}
	}
	calculated[row][col]=true;
	return cell_values[row][col];
}
