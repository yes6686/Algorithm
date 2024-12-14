#include <iostream>
using namespace std;

int arr[6][6];
pair<int, int> arrc[26];
int s[26];
int b[6][6];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
			arrc[arr[i][j]].first = i;
			arrc[arr[i][j]].second = j;

		}
	}
	for (int i = 1; i <= 25; i++) {
		cin >> s[i];
	}

	for (int i = 1; i <= 25; i++) {
		int r = arrc[s[i]].first;
		int c = arrc[s[i]].second;
		b[r][c] = 1;
		// 가로검사
		int check = 1;
		for (int j = 1; j <= 5; j++) {
			if (b[r][j] == 0) {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			cnt++;
			if (cnt >= 3) {
				cout << i << '\n';
				return 0;
			}
		}
		check = 1;
		// 세로 검사
		for (int j = 1; j <= 5; j++) {
			if (b[j][c] == 0) {
				check = 0;
			}
		}
		if (check == 1) {
			cnt++;
			if (cnt >= 3) {
				cout << i << '\n';
				return 0;
			}
		}
		// 대각선 검사
		if (r == c) {
			check = 1;
			for (int j = 1; j <= 5; j++) {
				if (b[j][j] == 0) {
					check = 0;
				}
			}
			if (check == 1) {
				cnt++;
				if (cnt >= 3) {
					cout << i << '\n';
					return 0;
				}
			}
		}
		if (r == 6 - c) {
			check = 1;
			for (int j = 1; j <= 5; j++) {
				if (b[j][6 - j] == 0) {
					check = 0;
				}
			}
			if (check == 1) {
				cnt++;
				if (cnt >= 3) {
					cout << i << '\n';
					return 0;
				}
			}
		}
	}
}