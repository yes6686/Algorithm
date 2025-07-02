#include <iostream>
#include <queue>
using namespace std;

int parr[10];
int arr[1001][1001];
int ans[10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, p;
int check1 = 0;
int check2 = 0;
queue<pair<int, int>>q[10];

void go() {

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] >0) {
				q[arr[i][j]].push({ i,j });
			}
		}
	}
	
	while (true) {
		check1 = 0;
		for (int h = 1;h <= 9;h++) {			
			if (q[h].empty()) continue;
			queue<pair<int, int>>cq;
			for (int l = 1; l <= parr[h]; l++) {
				check2 = 0;
				while (!q[h].empty()) {
					int cx = q[h].front().first;
					int cy = q[h].front().second;
					q[h].pop();
					for (int i = 0;i < 4;i++) {
						int nx = cx + dx[i];
						int ny = cy + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
						if (arr[nx][ny] == -1 || arr[nx][ny] > 0) continue;
						arr[nx][ny] = h;
						check1 = 1;
						check2 = 1;
						cq.push({ nx,ny });
					}
				}
				swap(q[h], cq);
				
				if (check2 == 0) break;
			}
		}
		if (check1 == 0) break;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> p;

	for (int i = 1;i <= p;i++) {
		cin >> parr[i];
	}

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			if (s[j] >='1' && s[j]<='9') {
				arr[i][j] = s[j] - '0';
			}
			else if (s[j] == '#') {
				arr[i][j] = -1;
			}
		}
	}

	go();

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] > 0) {
				ans[arr[i][j]]++;
			}
		}
	}

	for (int i = 1;i <= p;i++) {
		cout << ans[i] << ' ';
	}

}