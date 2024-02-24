#include <iostream>
using namespace std;

int arr[30001];
int ans[30001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int maxAns = 0;
	for (int i = n; i >= 1; i--) {
		int cnt = 2;
		int x = n;
		int c = i;
		arr[0] = n;
		arr[1] = i;
		while (1) {
			c = x - c;
			x = x - c;
			if (c < 0) break;
			arr[cnt] = c;
			cnt++;
		}
		if (maxAns < cnt) {
			maxAns = cnt;
			for (int i = 0; i < maxAns; i++) {
				ans[i] = arr[i];
			}
		}
	}
	cout << maxAns<<'\n';
	for (int i = 0; i < maxAns; i++) {
		cout << ans[i] << ' ';
	}
}