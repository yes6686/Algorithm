#include <iostream>
#include <math.h>
using namespace std;

int dis[100001];
pair<int, int>arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int totalDis = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i < n; i++) {
		int dx = abs(arr[i].first - arr[i-1].first);
		int dy = abs(arr[i].second - arr[i - 1].second);

		totalDis += (dx + dy);
		dis[i] = dx + dy;
	}

	int minDis = totalDis;
	for (int i = 2; i < n; i++) {
		int dx = abs(arr[i].first - arr[i - 2].first);
		int dy = abs(arr[i].second - arr[i - 2].second);
		int cd = dx + dy;
		minDis = min(minDis, totalDis + cd - dis[i] - dis[i - 1]);
	}
	cout << minDis;
}