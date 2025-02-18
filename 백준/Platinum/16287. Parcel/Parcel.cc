#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[5001];

pair<int,int> arrs[400001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, n;
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			arrs[arr[i] + arr[j]] = { arr[i],arr[j] };
		}
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int s = w - (arr[i] + arr[j]);
			if (s <= 2 || s>400000) continue;
			if (arrs[s].first == 0) continue;
			if (arrs[s].first != arr[i] && arrs[s].first != arr[j]
				&& arrs[s].second!=arr[i] && arrs[s].second!=arr[j]) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';
}