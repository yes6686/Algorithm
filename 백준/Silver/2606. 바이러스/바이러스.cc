#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int c[101];
int cnt = 0;
queue<int>q;
vector<int>v[101];
void DFS(int x) {
	if (c[x]) return;
	c[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		DFS(k);
	}
	cnt++;
}
int main() {
	int n,k;
	cin >> n>>k;
	int x,y;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1);
	cout << cnt - 1;
}