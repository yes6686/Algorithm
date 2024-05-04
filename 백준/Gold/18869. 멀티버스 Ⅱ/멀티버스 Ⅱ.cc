#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
pair<int, int> arr[10001];
map<string, int>mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[j].first;
			arr[j].second = j + 1;
		}
		sort(arr, arr + n);
		string s = "";

		for (int j = 0; j < n; j++) {
			s += arr[j].second + '0';
		}
		for (int j = 0; j < n - 1; j++) {
			if (arr[j].first == arr[j + 1].first) {
				s += arr[j].second + '0';
				s += arr[j+1].second + '0';
			}
		}
		mp[s]++;
	}
	int ans = 0;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		int k = iter->second;
		ans += k * (k - 1) / 2;
	}
	cout << ans;
}