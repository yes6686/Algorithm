#include <iostream>
using namespace std;

int arr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) s = arr[i];
		if (i == n - 1) e = arr[i];
	}
	s--; e--;
	int cnt = n - 3;

	if (s > e) {
		int d = s - e;
		if (cnt >= d) {
			cnt -= d;
			s = e;
			if ((s - cnt / 2) < 0) cout << 0 << '\n';
			else
				cout << s - cnt / 2 << '\n';
		}
		else {
			s -= cnt;
			cnt = 0;
			cout << s << '\n';
		}
	}
	else {
		int d = e - s;
		if (cnt >= d) {
			cnt -= d;
			e = s;
			if ((e - cnt / 2) < 0) cout << 0 << '\n';
			else
				cout << e - cnt / 2 << '\n';
		}
		else {
			e -= cnt;
			cnt = 0;
			cout << e << '\n';
		}
	}
}