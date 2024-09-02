#include <iostream>
using namespace std;

int arr[10001];
int s[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) s[i] = arr[i];
		else {
			s[i] = s[i - 1] + arr[i];
		}
	}

	int ans = 0;

	for (int i = n-1; i >= 0 ; i--) {
		if (s[i] == m) {
			ans++;
			break;
		}
		else if (s[i] < m) break;
		for (int j = 0; j < i; j++) {
			if (s[i] - s[j] == m) {
				ans++;
				break;
			}
			else if (s[i] - s[j] < m) {
				break;
			}
		}
	}
	cout << ans;
}