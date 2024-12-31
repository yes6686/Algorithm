#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int>arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	for (int i = 0; i < 11; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + 11);
	int ans = 0;
	int t = 0;
	for (int i = 0; i < 11; i++) {
		t += arr[i].first;
		ans += t + (20 * arr[i].second);
	}
	cout << ans << '\n';

}