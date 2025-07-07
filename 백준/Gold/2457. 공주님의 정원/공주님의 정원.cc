#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int>arr[100001];
queue<pair<pair<int, int>,int>>q;
int marr[13];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1;i <= 12;i++) {
		if (i == 4 || i == 6 || i == 9 || i == 11) {
			marr[i] = 30;
		}
		else if (i == 2) {
			marr[i] = 28;
		}
		else {
			marr[i] = 31;
		}
	}

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c <= 2 || (c == 3 && d == 1)) {
			arr[i].first = 9999999;
			continue;
		}
		for (int j = 1;j < a;j++) {
			arr[i].first += marr[j];
		}
		arr[i].first += b;

		for (int j = 1;j < c;j++) {
			arr[i].second += marr[j];
		}
		arr[i].second += (d-1);
	}


	int as = 0;
	int ae = 0;
	for (int i = 1;i <= 2;i++) {
		as += marr[i];
	}
	as += 1;

	for (int i = 1;i <= 10;i++) {
		ae += marr[i];
	}
	ae += 30;
	sort(arr, arr + n);
	int ans = 100001;
	int si = 0;
	int maxS = -1;
	for (int i = 0;i < n;i++) {
		if (arr[i].first <= as && arr[i].second >= as) {
			if (maxS <= arr[i].second) {
				maxS = arr[i].second;
				si = i;
			}
		}
	}
	if (maxS == -1) {
		cout << 0 << '\n';
		return 0;
	}
	else if (arr[si].second >= ae) {
		cout << 1 << '\n';
		return 0;
	}
	q.push({ {arr[si].first,arr[si].second},1 });
	for (int i = si+1;i < n;i++) {
		if (arr[i].first == 9999999) break;
		while (!q.empty()) {
			int f = q.front().first.first;
			int k = q.front().first.second;
			int d = q.front().second;
			if (k + 1 < arr[i].first) {
				q.pop();
			}
			else {				
				if (arr[i].second >= ae) {
					ans = min(ans, d+1);
					q.pop();
					break;
				}
				else {
					if (arr[i].second > k) {
						if (f == arr[i].first) {
							q.pop();
							q.push({ {arr[i].first,arr[i].second},d });
						}
						else {
							q.push({ {arr[i].first,arr[i].second},d + 1 });
						}
					}
					break;
				}		
			}
		}
	}
	if (ans == 100001)	cout<<0<<'\n';	
	else cout << ans << '\n';
}