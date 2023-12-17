#include <iostream>
#include <vector>
using namespace std;
string s[11];
int arr[12][12];
int minCnt = 101;
vector<vector<int>>V;
vector<int>v[12];

void dfs(int x, int y, int k, int cnt, vector<vector<int>>v1) {

	if (x == 10 && y == 11) {
		int check = 1;
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				if (v1[i][j] == 1) {
					check = 0;
					break;
				}
			}
			if (check == 0) {
				break;
			}
		}
		if (check) {
			minCnt = min(minCnt, cnt);
		}

		return;
	}

	if (y == 11) {
		dfs(x + 1, 1, 1, cnt, v1);
		return;
	}
	if (x == 1) {
		if (k == 1) {
			if (v1[x][y] == 1) {
				dfs(x, y + 1, 1, cnt, v1);
				dfs(x, y + 1, 0, cnt, v1);
			}
			else {
				v1[x][y] = 1;
				v1[x][y - 1] = v1[x][y - 1] == 1 ? 0 : 1;
				v1[x][y + 1] = v1[x][y + 1] == 1 ? 0 : 1;
				v1[x + 1][y] = v1[x + 1][y] == 1 ? 0 : 1;
				dfs(x, y + 1, 1, cnt + 1, v1);
				dfs(x, y + 1, 0, cnt + 1, v1);
			}
		}
		else {
			if (v1[x][y] == 0) {
				dfs(x, y + 1, 1, cnt, v1);
				dfs(x, y + 1, 0, cnt, v1);
			}
			else {
				v1[x][y] = 0;
				v1[x][y - 1] = v1[x][y - 1] == 1 ? 0 : 1;
				v1[x][y + 1] = v1[x][y + 1] == 1 ? 0 : 1;
				v1[x + 1][y] = v1[x + 1][y] == 1 ? 0 : 1;
				dfs(x, y + 1, 1, cnt + 1, v1);
				dfs(x, y + 1, 0, cnt + 1, v1);
			}
		}
	}
	else {
		if (v1[x - 1][y] == 1) {
			if (v1[x][y] == 1) {
				v1[x][y] = 0;
				v1[x][y - 1] = v1[x][y - 1] == 1 ? 0 : 1;
				v1[x][y + 1] = v1[x][y + 1] == 1 ? 0 : 1;
				v1[x + 1][y] = v1[x + 1][y] == 1 ? 0 : 1;
				v1[x - 1][y] = v1[x - 1][y] == 1 ? 0 : 1;
				dfs(x, y + 1, 1, cnt + 1, v1);
			}
			else {
				v1[x][y] = 1;
				v1[x][y - 1] = v1[x][y - 1] == 1 ? 0 : 1;
				v1[x][y + 1] = v1[x][y + 1] == 1 ? 0 : 1;
				v1[x + 1][y] = v1[x + 1][y] == 1 ? 0 : 1;
				v1[x - 1][y] = v1[x - 1][y] == 1 ? 0 : 1;
				dfs(x, y + 1, 1, cnt + 1, v1);
			}
		}
		else if (v1[x - 1][y] == 0) {
			dfs(x, y + 1, 1, cnt, v1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		v[0].push_back(0);
	}
	V.push_back(v[0]);
	for (int i = 0; i < 10; i++) {
		cin >> s[i];
		v[i + 1].push_back(0);
		for (int j = 0; j < 10; j++) {
			if (s[i][j] == '#') {
				arr[i + 1][j + 1] = 0;
				v[i + 1].push_back(0);
			}
			else {
				arr[i + 1][j + 1] = 1;
				v[i + 1].push_back(1);
			}
		}
		v[i + 1].push_back(0);
		V.push_back(v[i+1]);
	}
	for (int i = 0; i < 12; i++) {
		v[11].push_back(0);
	}
	V.push_back(v[11]);
	dfs(1, 1, 1, 0, V);
	dfs(1, 1, 0, 0, V);

	if (minCnt == 101) cout << -1;
	else
		cout << minCnt;

}