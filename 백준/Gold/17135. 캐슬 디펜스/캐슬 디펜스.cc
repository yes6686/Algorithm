#include <iostream>
#include <string.h>
using namespace std;

int enemy[16][16];
int diedEnemy[16][16];
int archer[16];

int n, m, d;

int distanceValue(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int maxAns = 0;

void go() {
	int cnt = 0;
	int arrEnemy[16][16];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arrEnemy[i][j] = enemy[i][j];
		}
	}
	while (1) {
		for (int i = 0; i < m; i++) {
			if (archer[i] == 1) {
				int fx=-1, fy=-1;
				int minD = 30;
				for (int t = n - 1; t >= 0; t--) {
					for (int h = 0; h < m; h++) {
						if (arrEnemy[t][h] == 1 && distanceValue(t, h, n, i) <= d) {
							if (minD > distanceValue(t, h, n, i)) {
								minD = distanceValue(t, h, n, i);
								fx = t;
								fy = h;
							}
							if (minD == distanceValue(t, h, n, i)) {
								if (fy > h) {
									fx = t;
									fy = h;
								}
							}
						}
					}
				}
				if (fx != -1) {
					diedEnemy[fx][fy] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (diedEnemy[i][j] == 1) {
					diedEnemy[i][j] = 0;
					arrEnemy[i][j] = 0;
					cnt++;
				}
			}
		}
		int exitCheck = 1;
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < m; j++) {
				if (i == n - 1) {
					if (arrEnemy[i][j] == 1) {
						arrEnemy[i][j] = 0;
					}
				}
				if (arrEnemy[i - 1][j] == 1) {
					exitCheck = 0;
					arrEnemy[i][j] = 1;
					arrEnemy[i - 1][j] = 0;
				}
			}
		}
		if (exitCheck == 1) {
			break;
		}
	}

	maxAns = max(maxAns, cnt);
}

void solve(int depth,int cnt) {
	if (cnt >= 3) {
		go();
		return;
	}

	for (int i = depth; i < m; i++) {
		archer[i] = 1;
		solve(i + 1, cnt + 1);
		archer[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> enemy[i][j];
		}
	}
	solve(0,0);
	
	cout << maxAns;
}