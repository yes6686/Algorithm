// 3
#include <iostream>
using namespace std;

int arr[101][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'B') {
				arr[i][j] = 1;
			}
			else if (s[j] == 'X') {
				arr[i][j] = 0;
			}
		}
	}
	if (m % 2 == 1) {
		for (int i = 0; i < n; i++) {
			if (arr[i][m / 2] == 0 && arr[i][m / 2 - 1] == 0
				&& arr[i][m / 2 + 1] == 0) {
				arr[i][m / 2] = 2;
				arr[i][m / 2 - 1] = 3;
				arr[i][m / 2 + 1] = 3;
				cout << "YES" << '\n';
				for (int t = 0; t < n; t++) {
					for (int k = 0; k < m; k++) {
						if (arr[t][k] == 0 || arr[t][k] == 1) {
							cout << "B";
						}
						else if (arr[t][k] == 2) {
							cout << "Y";
						}
						else {
							cout << "W";
						}
					}
					cout << '\n';
				}
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (arr[i][m / 2-1] == 0 && arr[i][m/2]==0
				&&arr[i][m / 2 - 2] == 0
				&& arr[i][m / 2 + 1] == 0) {
				arr[i][m / 2-1] = 2;
				arr[i][m / 2] = 2;
				arr[i][m / 2 - 2] = 3;
				arr[i][m / 2 + 1] = 3;
				cout << "YES" << '\n';
				for (int t = 0; t < n; t++) {
					for (int k = 0; k < m; k++) {
						if (arr[t][k] == 0 || arr[t][k] == 1) {
							cout << "B";
						}
						else if (arr[t][k] == 2) {
							cout << "Y";
						}
						else {
							cout << "W";
						}
					}
					cout << '\n';
				}
				return 0;
			}
		}
	}
	cout << "NO";

}