#include <iostream>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			int k = i;
			for (int j = k; j >= 1; j--) {
				if (arr[j] < arr[j - 1]) {
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}