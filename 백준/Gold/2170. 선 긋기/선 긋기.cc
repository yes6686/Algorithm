#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);

	int s = arr[0].first;
	int e = arr[0].second;
	int ans = 0;

	for (int i = 1;i < n;i++) {
		if (e <= arr[i].first) {
			ans += (e - s);
			s = arr[i].first;
			e = arr[i].second;
		}
		else {
			if (e < arr[i].second) {
				e = arr[i].second;
			}
		}
	}
	ans += (e - s);
	cout << ans << '\n';
}