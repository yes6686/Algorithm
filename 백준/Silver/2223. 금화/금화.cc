#include <iostream>
using namespace std;

pair<int, int> arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int moveCnt = 0;
	int t, x, m;
	cin >> t >> x >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int cnt = 0;
	while (t--) {
		int check = 1;
		for (int i = 0; i < m; i++) {
			if (arr[i].first - arr[i].second <= 0) {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			cnt+=x;
			moveCnt++;
			for (int i = 0; i < m; i++) {
				arr[i].first -= arr[i].second;
			}
		}
		else {
			if (moveCnt == 0) continue;
			moveCnt--;
			for (int i = 0; i < m; i++) {
				arr[i].first += arr[i].second;
			}
		}
	}
	cout << cnt;
	
}