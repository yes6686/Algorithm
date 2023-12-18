#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int parent[255];

string s[51];
int arr[51][51];
int stNum[51][51];
int c[51][51];
int visited[51][51];
struct st {
	int x, y;
};

struct edge {
	int a, b;
	int dis;
};

edge Ed[60001];
st St[255];

int GetParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent[x]);
}

void unionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int findParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);

	if (a == b) return 1;
	else return 0;
}

bool compare(edge a, edge b) {
	return a.dis < b.dis;
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int kk = 0;
void dfs(int x, int y, int xx, int yy) {
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c[i][j] = 0;
		}
	}
	queue<pair<pair<int, int>, int>>q;
	q.push(make_pair(make_pair(x,y), 0));
	c[x][y] = 1;
	while (!q.empty()) {
		int rx = q.front().first.first;
		int ry = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (rx == xx && ry == yy) {
			Ed[kk].a = stNum[x][y];
			Ed[kk].b = stNum[xx][yy];
			Ed[kk].dis = cnt;
			kk++;
			visited[xx][yy] = 0;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = rx + dx[i];
			int ny = ry + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
				
				if (arr[nx][ny] == 1) continue;
				if (c[nx][ny] == 1) continue;
				c[nx][ny] = 1;
				q.push(make_pair(make_pair(nx, ny),cnt+1));		
			}
		}
	}
}


int main() {

	cin >> n >> m;
	for (int i = 1; i <= 255; i++) {
		parent[i] = i;
	}
	int ss = 0;
	int starti = 0;
	int startj = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == '1' || s[i][j] == '0') {
				arr[i + 1][j + 1] = s[i][j] - '0';
			}
			else if (s[i][j] == 'S' || s[i][j] == 'K') {
				visited[i+1][j+1] = 1;
				St[ss].x = i + 1;
				St[ss].y = j + 1;
				stNum[i + 1][j + 1] = ss;
				ss++;
				arr[i + 1][j + 1] = 2;
				if (s[i][j] == 'S') {
					visited[i + 1][j + 1] = 0;
					starti = i + 1;
					startj = j + 1;
				}
			}
			
		}
	}
	for (int i = 0; i < ss; i++) {
		if (St[i].x != starti || St[i].y != startj) {
			dfs(starti, startj, St[i].x, St[i].y);
		}
	}
	for (int i = 0; i < ss - 1; i++) {
		for (int j = i + 1; j < ss; j++) {
			dfs(St[i].x, St[i].y, St[j].x, St[j].y);
		
		}
	}
	sort(Ed, Ed + kk, compare);
	int sum = 0;
	for (int i = 0; i < kk; i++) {
		if (!findParent(Ed[i].a, Ed[i].b)) {
			unionParent(Ed[i].a, Ed[i].b);
			sum += Ed[i].dis;

		}
	}

	int check = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) {
				check = 0;
				break;
			}
		}
	}

	if (check == 1)
		cout << sum << '\n';
	else
		cout << -1 << '\n';
}