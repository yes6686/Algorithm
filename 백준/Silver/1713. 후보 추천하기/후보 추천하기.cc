#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int k;
	cin >> k;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		if (arr[x].first > 0) {
			arr[x].first++;
			continue;
		}

		if (cnt < n) {
			cnt++;
			arr[x].first = 1;
			arr[x].second = i;
		}

		else {
			int minA = 101;
			int minB = 101;
			int goi=0;
			for (int j = 1; j <= 100; j++) {
				if (arr[j].first > 0) {
					if (minA > arr[j].first) {
						minA = arr[j].first;
						minB = arr[j].second;
						goi = j;
					}
					if (minA == arr[j].first) {
						if (minB > arr[j].second) {
							minB = arr[j].second;
							goi = j;
						}
					}
				}
			}
			arr[goi].first = 0;
			arr[goi].second = 0;
			arr[x].first = 1;
			arr[x].second = i;
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (arr[i].first > 0) {
			cout << i << " ";
		}
	}
}