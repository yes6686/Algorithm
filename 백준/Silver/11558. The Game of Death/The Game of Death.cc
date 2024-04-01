#include <iostream>
#include <string.h>
using namespace std;

int arr[10001];
int s[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		int t = 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}
		while (arr[t] == 0) {
			arr[t] = 1;
			t = s[t];
			cnt++;
			if (t == n) {
				ans = cnt;
				break;
			}
		}
		cout << ans << '\n';
		memset(arr, 0, sizeof(arr));
	}
}