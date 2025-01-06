#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int>arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,l,k;
	cin >> n>>l>>k;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (cnt >= k) break;
		if (arr[i].first <= l) {
			sum += 140;
			cnt++;
		}
		else if (arr[i].second <= l) {
			sum += 100;
			cnt++;
		}
	}
	cout << sum << '\n';
}
