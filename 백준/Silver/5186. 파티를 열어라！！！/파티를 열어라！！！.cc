//1
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int Darr[501]; // 안취
int zarr[501]; //취취

priority_queue<int>pq[501]; // 내림차순

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int t = 1;
	while (T--) {
		int n, c, k;
		cin >> n >> c >> k;
		int x;
		char y;
		for (int i = 1; i <= n; i++) {
			cin >> x >> y;
			if (y == 'S') {
				Darr[x]++;
			}
			else {
				zarr[x]++;
			}
		}
		for (int i = 0; i < c; i++) {
			int a, b;
			cin >> a >> b;
			pq[a].push(b);
		}
		for (int i = 1; i <= k; i++) {
			while (!pq[i].empty()) {
				int a = i;
				int b = pq[i].top();
				pq[i].pop();
				if (Darr[a] > 0) {
					Darr[a]--;
					b--;
					if (zarr[a] >= b) {
						zarr[a] -= b;
					}
					else if (zarr[a] < b) {
						int kk = zarr[a];
						zarr[a] = 0;
						kk = b - kk;
						if (Darr[a] >= kk) {
							Darr[a] -= kk;
						}
						else {
							Darr[a] = 0;
						}
					}
				}
			}
		}
		int ans = 0;
		cout << "Data Set " << t++ << ":" << '\n';
		for (int i = 1; i <= k; i++) {
			ans += Darr[i];
			ans += zarr[i];
		}
		cout << ans << '\n';
		memset(Darr, 0, sizeof(Darr));
		memset(zarr, 0, sizeof(zarr));
	}
}