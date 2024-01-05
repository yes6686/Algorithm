#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int c1[1001];
int c2[1001];

vector<int>v[1001];
queue<int>q;

void DFS(int n) {
	if (c1[n]) return;
	c1[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		cout << x << ' ';
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int k = v[x][i];
			
			DFS(k);
		}
	}

}
void BFS(int n) {
	if (c2[n]) return;
	c2[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		cout << x << ' ';
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int k = v[x][i];
			if (!c2[k]) {
				q.push(k);
				c2[k] = 1;
			}
		}
	}

}
int main() {
	int n, m, s;
	cin >> n >> m >> s;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		sort(v[x].begin(), v[x].end());
		sort(v[y].begin(), v[y].end());
	}/*
	for (int i = 0; i < m; i++) {
		sort(v[1].begin(), v[i].end());
		
	}*/
	
	DFS(s);
	cout << endl;
	BFS(s);
}