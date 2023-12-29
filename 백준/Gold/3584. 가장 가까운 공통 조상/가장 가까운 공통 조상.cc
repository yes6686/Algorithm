#include <iostream>	
#include <vector>
using namespace std;

vector<int>v[10001];
vector<int>rv[10001];

int visited[10001];
int a, b;
int check = 1;
int ccheck = 1;

void dfs(int e, int r) {

	if (e == r) {
		ccheck = 0;
		return;
	}


	for (int i = 0; i < v[e].size(); i++) {
		int k = v[e][i];
		dfs(k, r);
	}
}



void dfs2(int x) {

	if (visited[x]) return;

	if (check == 0) {
		return;
	}
	if (x == b) {
		check = 0;
		return;
	}

	for (int i = 0; i < v[x].size(); i++) {
		int w = v[x][i];
		dfs2(w);
		if (w == b) {
			check = 0;
			break;
			
		}

	}
}

void dfs1(int x) {

	visited[x] = 1;



		for (int i = 0; i < rv[x].size(); i++) {
			int k = rv[x][i];
			check = 1;
			for (int j = 0; j < v[k].size(); j++) {
				int h = v[k][j];
				dfs2(h);
				if (check == 0) {
					cout << k << '\n';
					break;
				}
			}
			if (check == 0) {
				break;
			}
			else {
				dfs1(k);
			}
		}
	
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;
		int x, y;
		for (int i = 0; i < n-1; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			rv[y].push_back(x);
		}
		cin >> a >> b;
		if (a == b) {
			cout << a << '\n';
		}
		else {
			dfs(a, b);
			if (ccheck == 0) {
				cout << a << '\n';
			}
			else if (ccheck == 1) {
				dfs(b, a);
				if (ccheck == 0) {
					cout << b << '\n';
				}
				else {
					dfs1(a);
				}
			}
		}


		for (int i = 1; i <= n; i++) {
			v[i].clear();
			rv[i].clear();
			visited[i] = 0;
		}
		check = 1;
		ccheck = 1;
	}
}