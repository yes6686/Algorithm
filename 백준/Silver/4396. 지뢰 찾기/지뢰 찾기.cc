#include <iostream>
using namespace std;

int arr1[11][11];
int arr2[11][11];

int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				arr1[i][j] = 0;
			}
			else { // s[j] == '*'
				arr1[i][j] = 1;
			}
		}	
	}
	int check = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				arr2[i][j] = -1;
			}
			else if (arr1[i][j] == 1) {
				arr2[i][j] = -2;
				check = 1;
			}
			else { // s[j] == 'x'
				int cnt = 0;
				for (int t = 0; t < 8; t++) {
					int nx = i + dx[t];
					int ny = j + dy[t];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (arr1[nx][ny] == 1) {
						cnt++;
					}
				}
				arr2[i][j] = cnt;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check == 1 && arr1[i][j]==1) {
				cout << "*";
			}
			else if (arr2[i][j] == -1) {
				cout << ".";
			}
			else if (arr2[i][j] == -2) {

				cout << "*";
			}
			else {
				cout << arr2[i][j];
			}
		}
		cout << '\n';
	}
}