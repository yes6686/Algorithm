#include <iostream>
#include <vector>
using namespace std;
vector<int>v[501];
int c[501];
int cc[501];
int parent[501];
int cnt = 0;
int inDegree[501];
int check = 1;
void con(int p) {
	if (cc[p]) {
		check = 0;
		return;
	}
	if (c[p]) return;
	c[p] = 1;

	
		for (int i = 0; i < v[p].size(); i++) {
		int	k = v[p][i];
		if (c[k] == 0) {
			parent[k] = p;
			con(k);
		}
		else if (c[k] == 1 && parent[p] != k) {
			check = 0;
		}

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int s = 1;
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		int x, y;

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			if (x == y) {
				cc[x] = 1;
			}
			else {
				v[x].push_back(y);
				v[y].push_back(x);
				inDegree[y]++;
				inDegree[x]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			check = 1;
			if (inDegree[i] == 0 && cc[i]==0) {
				cnt++;
			}
			else if (c[i]==0 && cc[i]==0) {
				con(i);
				if (check == 1) {
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			cout << "Case " << s << ": No trees." << '\n';
		}
		else if (cnt == 1) {
			cout << "Case " << s << ": There is one tree." << '\n';
		}
		else {
			cout << "Case " << s << ": A forest of " <<cnt<< " trees." << '\n';
		}
		s++;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			c[i] = 0;
			cc[i] = 0;
			inDegree[i] = 0;
			parent[i] = 0;
		}
	}



	

}