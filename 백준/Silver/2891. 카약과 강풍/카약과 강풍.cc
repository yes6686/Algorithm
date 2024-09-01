#include <iostream>
using namespace std;

int arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	

	int n, s, r;
	cin >> n >> s >> r;
	int x;
	for (int i = 0; i < s; i++) {
		cin >> x;
		arr[x] = -1;
	}
	for (int i = 0; i < r; i++) {
		cin >> x;
		arr[x]++;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			if (arr[i - 1] == -1) {
				arr[i] = 0;
				arr[i - 1] = 0;
			}
			else if (arr[i + 1] == -1) {
				arr[i] = 0;
				arr[i + 1] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == -1)ans++;
	}
	cout << ans;
}