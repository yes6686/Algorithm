#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[11][11];
int w[11][11];
int addarr[11][11];


int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
vector<int>v[1001][1001];
int n, m, k;

void go() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (w[i][j]) {
				sort(v[i][j].begin(), v[i][j].end());
				for (int t = 0; t < v[i][j].size(); t++) {
					int k = v[i][j][t];
					if (arr[i][j] >= k) {
						arr[i][j] -= k;
						v[i][j][t] = k + 1;
					}
					else {
						for (int h = t; h < v[i][j].size(); h++) {
							arr[i][j] += v[i][j][h] / 2;
						}
						int last = v[i][j].size();
						for (int h = t; h < last; h++) {
							v[i][j].pop_back();
						}
						if (v[i][j].size() == 0) w[i][j] = 0;
						break;
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += addarr[i][j];
			if (w[i][j]) {
				for (int t = 0; t < v[i][j].size(); t++) {
					int k = v[i][j][t];
					if (k % 5 == 0 && k) {
						for (int h = 0; h < 8; h++) {
							if (i + dx[h] <= 0 || j + dy[h] <= 0
								|| i + dx[h] > n || j + dy[h] > n) continue;
							v[i + dx[h]][j + dy[h]].push_back(1);
							w[i + dx[h]][j + dy[h]] = 1;
						}

					}
				}
			}
		}
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 5;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> addarr[i][j];
		}
	}
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x][y].push_back(z);
		w[x][y] = 1;

	}

	while (k--) {
		go();
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += v[i][j].size();
		}
	}
	cout << cnt;

}