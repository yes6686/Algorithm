#include <iostream>
using namespace std;

int arr[250001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, n;
	cin >> x >> n;
	int sum = 0;
	for (int i = 0; i < x; i++) {
		cin >> arr[i];
		if (i >= n) continue;
		sum += arr[i];
	}
	int s = sum;
	int maxAns = sum;
	int cnt = 1;
	for (int i = n; i < x; i++) {
		if (s + arr[i] - arr[i - n] > maxAns) {
			maxAns = s + arr[i] - arr[i - n];
			cnt = 1;
		}
		else if (s + arr[i] - arr[i - n] == maxAns) {
			cnt++;
		}
		s = s + arr[i] - arr[i - n];
	}
	if (maxAns == 0) {
		cout << "SAD" << '\n';
		return 0;
	}
	cout << maxAns << '\n' << cnt << '\n';
}