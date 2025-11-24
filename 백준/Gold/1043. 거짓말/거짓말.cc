#include <iostream>
#include <queue>
using namespace std;

int arr[51][51];
int ch[51];
int t[51];

int main() {
	int n, m;
	cin >> n >> m;
	int tp;
	cin >> tp;
	for (int i = 0; i < tp; i++) {
		int x;
		cin >> x;
		t[x] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}
	while (1) {
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			int check = 0;
			if (ch[i] == 1) continue;
			for (int j = 0; j < 51; j++) {
				if (arr[i][j] == 0) break;
				if (t[arr[i][j]] == 1) {
					cnt++;
					check = 1;
				}
			}
			if (check == 1) {
				for (int j = 0; j < 51; j++) {
					if (arr[i][j] == 0) break;
					t[arr[i][j]] = 1;
					ch[i] = 1;
				}
			}
		}
		if (cnt == 0) break;
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (ch[i]==0) {
			ans++;
		}
	}
	cout << ans;
}