#include <iostream>
#include <algorithm>
using namespace std;

double arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n;j++) {
			int a;
			double b;
			cin >> a >> b;
			arr[a-1] = max(arr[a-1], b);
		}
	}
	sort(arr, arr + n);
	double ans = 0;
	for (int i = n - 1; i >= n-1-k+1; i--) {
		ans += arr[i];
	}
	cout << fixed;
	cout.precision(1);
	cout << ans;
}