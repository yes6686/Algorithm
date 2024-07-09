#include <iostream>
using namespace std;

int arr[51][51];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (arr[i][j] == s[j] - '0') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arr[i][j] == 1) {
				for (int t = i; t < i + 3; t++) {
					for (int k = j; k < j + 3; k++) {
						arr[t][k] = (arr[t][k] == 1) ? 0 : 1;
					}
				}
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;
}