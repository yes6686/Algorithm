#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1001][1001];
int visited[100001];
int n, k, m;

vector<int>v[1001];

int cnt = 2;
int ans = -1;

void bfs() {

	while (true) {
		int check = 0;
		for (int i = 0;i < m;i++) {
			int cc = 0;
			for (int j = 0;j < v[i].size();j++) {
				int k = v[i][j];
				if (visited[k] == cnt) {
					check = 1;
					cc = 1;
				}
			}
			if (cc == 1) {
				for (int j = 0;j < v[i].size();j++) {
					int k = v[i][j];
					if (visited[k] == 0) {
						visited[k] = cnt + 1;
						if (k == n) {
							ans = visited[k];
							return;
						}
					}
				}
				v[i].clear();
			}	
		}
		cnt++;
		if (check == 0) {
			break;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> m;
	if (n == 1 && k == 1 && m == 1) {
		cout << 1 << '\n';
		return 0;
	}
	int ansC = 0;
	for (int i = 0;i < m;i++) {
		int oneCheck = 0;
		for (int j = 0;j < k;j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
			if (x == 1) {
				oneCheck = 1;
			}
		}
		if (oneCheck == 1) {
			for (int j = 0;j < v[i].size();j++) {
				int k = v[i][j];
				visited[k] = cnt;
				if (k == n) ansC = 1;
			}
			v[i].clear();
		}
	}

	if (ansC == 1) {
		cout << 2 << '\n';
		return 0;
	}

	bfs();
	cout << ans << '\n';
}