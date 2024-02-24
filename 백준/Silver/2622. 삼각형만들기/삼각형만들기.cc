#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n/3; i++) {
		for (int j = i; j <= n; j++) {
			int k = n - (i + j);
			if (i + j > k && k>=j) {
				cnt++;
			}
		}
	}
	cout << cnt;
}