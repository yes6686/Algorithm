#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

pair<int,pair<int,int>> arr[101];
pair<int,pair<int,int>> tarr[101];
int sarr[101][101];

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		return a.second.first < b.second.first;
	}
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		for (int i = 0; i < m; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			if (sarr[a][b] < s) {
				arr[a] = { arr[a].first - sarr[a][b] + s, {arr[a].second.first+1,i} };
				sarr[a][b] = max(sarr[a][b], s);
			}
			else {
				arr[a] = { arr[a].first, {arr[a].second.first+1,i} };
			}
			tarr[a] = arr[a];
		}
		sort(arr+1, arr + n+1, compare);
		for (int i = 1; i <= n; i++) {
			if (arr[i] == tarr[t]) {
				cout << i << '\n';
				break;
			}
		}
		memset(arr, 0, sizeof(arr));
		memset(tarr, 0, sizeof(tarr));
		memset(sarr, 0, sizeof(sarr));
	}
}