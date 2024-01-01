#include <iostream>
using namespace std;
int arr[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, b;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		
		}
	}
	int k;
	int time = 0;
	int mintime = 1e9;
	int maxheight = -1;
	
		for (int t = 0; t <= 256; t++) {
			time = 0;
			k = b;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (arr[i][j] > t) {
						time += (arr[i][j] - t) * 2;
						k +=  (arr[i][j]-t);
					}
					else {
						time += (t - arr[i][j]);
						k -= (t - arr[i][j]);
					}
					
				}
			}
			if (k >= 0) {
			 if (mintime >= time) {
				mintime = time;
				maxheight = t;
				}
			}
		}
	
		cout << mintime << ' ' << maxheight;
}