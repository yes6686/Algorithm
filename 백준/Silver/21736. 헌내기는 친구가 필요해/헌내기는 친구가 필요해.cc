#include <iostream>
using namespace std;
char arr[601][601];
int n, m;
int cnt = 0;
int c[601][601];
void dfs(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m) {
		return;
	}
	if (c[i][j]) return;
	c[i][j] = 1;
	if (arr[i][j] == 'X') {
		return;
	}
	if (arr[i][j] == 'P') {
		cnt++;
	}
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j+1);
	dfs(i, j-1);
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int indexi=0;
	int indexj=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				indexi = i;
				indexj = j;
			}
		}
	}
	dfs(indexi, indexj);
	if (cnt == 0) {
		cout << "TT" << '\n';
	}else
	cout << cnt << endl;		
}