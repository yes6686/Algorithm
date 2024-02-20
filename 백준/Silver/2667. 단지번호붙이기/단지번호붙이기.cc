#include <iostream>
#include <queue>
using namespace std;

int arr[26][26];

queue<pair<int,int>>q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0,1,-1 };
int visited[26][26];

priority_queue<int,vector<int>, greater<int>>pq;

int bfs(int x,int y,int n) {
	int cnt = 0;
	q.push({ x,y });
	cnt++;
	visited[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] || arr[nx][ny] == 0) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				count++;
				pq.push(bfs(i, j, n));
			}
		}
	}
	cout << count << '\n';
	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
}