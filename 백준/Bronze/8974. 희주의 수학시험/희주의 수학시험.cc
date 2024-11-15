#include <iostream>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt = 0;
	int n = 1;
	while (true) {

		for (int i = 0; i < n; i++) {
			arr[cnt] = n;
			cnt++;
			if (cnt >= 1000) break;
		}
		n++;
		if (cnt >= 1000) break;
	}

	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = a-1; i < b; i++) {
		ans += arr[i];
	}
	cout << ans;
}