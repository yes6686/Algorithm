#include <iostream>
using namespace std;

int arr[1001][1001];
int cc[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 1;
	int maxCnt = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= 5; j++) {	
			for (int t = 1; t <= n; t++) {
				if (i == t) continue;
				if (arr[i][j] == arr[t][j]) {
					cc[t] = 1;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (cc[j] == 1) {
				cnt++;
				cc[j] = 0;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
			ans = i;
		}
	}
	cout << ans;
}