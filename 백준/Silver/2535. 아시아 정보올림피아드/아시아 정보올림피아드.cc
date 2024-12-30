#include <iostream>
#include <algorithm>
using namespace std;

pair<int, pair<int, int>>arr[101];
int cnt[101];
bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.second.second > b.second.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
	}
	sort(arr, arr + n, compare);
	int totalCnt = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[arr[i].first] >= 2) {
			continue;
		}
		cnt[arr[i].first]++;
		cout << arr[i].first << " " << arr[i].second.first << '\n';
		totalCnt++;
		if (totalCnt >= 3) break;
	}
}