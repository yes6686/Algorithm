#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[101][101];
int cmax[101];
int cnt[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
		sort(arr[i], arr[i] + m);
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cmax[j] = max(cmax[j], arr[i][j]);
		}
	}

	int maxCnt = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == cmax[j]) {
				cnt[i]++;
				maxCnt = max(maxCnt, cnt[i]);
			}
		}
	}

	for (int i = 0;i < n;i++) {
		if (cnt[i] == maxCnt) {
			cout << i + 1 << " ";
		}
	}
}