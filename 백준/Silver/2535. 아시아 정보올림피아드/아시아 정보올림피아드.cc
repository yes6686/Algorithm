#include <iostream>
#include <algorithm>
using namespace std;

pair<int, pair<int, int>> arr[101];
int cnt[101];
int totalPriceCnt = 3;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
	}
	sort(arr, arr + n,compare);
	for (int i = 0; i < n; i++) {
		if (totalPriceCnt == 0) break;
		if (cnt[arr[i].second.first] < 2) {
			cnt[arr[i].second.first]++;
			totalPriceCnt--;
			cout << arr[i].second.first << ' ' << arr[i].second.second << '\n';
		}
	}
}