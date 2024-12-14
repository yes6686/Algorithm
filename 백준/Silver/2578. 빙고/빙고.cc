#include <iostream>
using namespace std;

pair<int, int> arr[26];
int s[26];
int totalCnt = 0;

int wCnt[6]; // 가로 카운트
int vCnt[6]; // 세로 카운트
int dCnt[3]; // 대각선 카운트

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int x;
			cin >> x;
			arr[x].first = i;
			arr[x].second = j;

		}
	}
	for (int i = 1; i <= 25; i++) {
		cin >> s[i];
	}

	for (int i = 1; i <= 25; i++) {
		auto [r, c] = arr[s[i]]; // 좌표 가져오기
		wCnt[r]++;
		vCnt[c]++;
		if (wCnt[r] == 5) {
			totalCnt++;
			if (totalCnt >= 3) {
				cout << i << '\n';
				return 0;
			}
		}
		if (vCnt[c] == 5) {
			totalCnt++;
			if (totalCnt >= 3) {
				cout << i << '\n';
				return 0;
			}
		}
		if (r == c) {
			dCnt[1]++;
			if (dCnt[1] == 5) {
				totalCnt++;
				if (totalCnt >= 3) {
					cout << i << '\n';
					return 0;
				}
			}
		}
		if (r == 6 - c) {
			dCnt[2]++;
			if (dCnt[2] == 5) {
				totalCnt++;
				if (totalCnt >= 3) {
					cout << i << '\n';
					return 0;
				}
			}
		}
	}
}