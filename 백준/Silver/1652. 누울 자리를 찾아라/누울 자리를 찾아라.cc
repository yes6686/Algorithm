#include <iostream>
using namespace std;

string s[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int w = 0; // 세로
	int h = 0; // 가로
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		int check = 0;
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == '.') {
				cnt++;
				if (check == 0 && cnt>=2) {
					check = 1;
					w++;
				}
			}
			else {
				check = 0;
				cnt = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		int check = 0;
		for (int j = 0; j < s[i].size(); j++) {
			if (s[j][i] == '.') {
				cnt++;
				if (check == 0 && cnt >= 2) {
					check = 1;
					h++;
				}
			}
			else {
				check = 0;
				cnt = 0;
			}
		}
	}
	cout << w << ' ' << h;
}