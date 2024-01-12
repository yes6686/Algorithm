#include <iostream>
#include <vector>
using namespace std;
vector<int>v[1001];
int c[1001];
int cnt = 0;
int check = 0;
void DFS(int x) {
	if (c[x]) return;
	c[x] = 1;
	check = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		DFS(k);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);	
		v[b].push_back(a);	

	}
	for (int i = 1; i <= n; i++) {
		DFS(i);
		if (check == 1) {
			cnt++;
		}
		check = 0;
	}
	cout << cnt << endl;

}