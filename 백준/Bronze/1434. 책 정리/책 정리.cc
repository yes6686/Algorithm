#include <iostream>
using namespace std;

int a[1001];
int b[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (a[j] >= b[i]) {
			a[j] -= b[i];
			cnt -= b[i];
		}
		else {
			j++;
			i--;
		}
	}
	cout << cnt;
}