#include <iostream>
using namespace std;

int arr1[500001];
int arr2[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	int cnt = 0;
	int w = 0;
	for (int i = 0; i < n; i++) {
		w += arr2[i];
		if (w < arr1[i]) {
			while (w < arr1[i]) {
				if (cnt == 0) break;
				w += x;
				cnt--;
			}
			if (w < arr1[i]) {
				cout << -1;
				return 0;
			}
		}
		else {
			while (true) {
				if (w - x >= arr1[i]) {
					cnt++;
					w -= x;
				}
				else {
					break;
				}
			}
		}
	}
	cout << cnt;
}