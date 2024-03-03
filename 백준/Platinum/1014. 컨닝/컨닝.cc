#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

string s[11];
int dp[11][1 << 10];
int n, m;

int bCheck(int p,int b) {
	for (int i = 0; i < m; i++) {
		if ((1 << i) & p) {
			if ((b & (1 << (i + 1)))) {
				return 0;
			}
			if (i != 0) {
				if ((b & (1 << (i - 1)))) {
					return 0;
				}
			}
		}
	}
	return 1;
}


int xCheck(int i,int b) {
	for (int j = 0; j < s[i].size(); j++) {
		if (s[i][j] == 'x' && (b & (1 << j))) {
			return 0;
		}
	}
	return 1;
}

int adjCheck(int b) {
	for (int i = 0; i < m - 1; i++) {
		if ((b & (3 << i))==(3<<i)) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	vector <pair<int, int>>base;
	for (int i = 0; i < (1<<m); i++) {
		if (adjCheck(i) == 1) {
			int c = 0;
			for (int j = 0; j < m; j++) {
				if ((i & (1 << j)) == (1 << j)) {
					c++;
				}
			}
			base.push_back({ i,c });
		}
	}
	int maxAns = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < base.size(); j++) {
			int ki = base[j].first;
			int kc = base[j].second;
			if (xCheck(i, ki) == 1) {
				for (int t = 0; t < base.size(); t++) {
					if (bCheck(base[t].first, ki) == 1) {
						dp[i][ki] = max(dp[i][ki], dp[i - 1][base[t].first] + kc);
						maxAns = max(maxAns, dp[i][ki]);
					}
				}
			}
		}
	}
	cout << maxAns << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}
		solve();
		memset(dp, 0, sizeof(dp));
	}
}