#include <iostream>
using namespace std;

int n, m, h;

int arr[31][11];
int con[11][11][31];
int check = 0;
int c[31][11];


struct edge {
	int x, y;
};
edge Ed[301];
int k = 0;

int ans = -1;


void dfs(int x, int y, int startn) {
	if (y == n + 1) {
		check = 1;
		return;

	}
	if (x == h + 1) {
		if (y != startn) {
			return;
		}
		else {
			dfs(1, startn + 1, startn + 1);
			return;
		}
	}
	

	if (arr[x][y] && arr[x][y - 1] && con[y-1][y][x]) {
		dfs(x + 1, y - 1, startn);
	}

	else if (arr[x][y] && arr[x][y + 1] &&con[y][y+1][x]) {
		dfs(x + 1, y + 1, startn);
	}
	else {
		dfs(x + 1, y, startn);
	}
}

void go(int zz) {
	//if (ans != -1) return;
	
	dfs(1, 1, 1);
	if (check == 1) {
		if (ans == -1) {
			ans = zz;
		}
		else {
			ans = min(ans, zz);
		}
		check = 0;
		return;
	}
	if (zz == 3) {
		return;
	}
	for (int i =0; i < k; i++) {
		if (con[Ed[i].y][Ed[i].y + 1][Ed[i].x] == 1) continue;
		if (arr[Ed[i].x][Ed[i].y] || arr[Ed[i].x][Ed[i].y + 1]) continue;
		arr[Ed[i].x][Ed[i].y] = 1;
		arr[Ed[i].x][Ed[i].y + 1] = 1;
		con[Ed[i].y][Ed[i].y + 1][Ed[i].x] = 1;
		go(zz + 1);
		arr[Ed[i].x][Ed[i].y] = 0;
		arr[Ed[i].x][Ed[i].y + 1] = 0;
		con[Ed[i].y][Ed[i].y + 1][Ed[i].x] = 0;
		
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[a][b + 1] = 1;
		con[b][b + 1][a] = 1;
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (!arr[i][j] && !arr[i][j + 1]) {
				Ed[k].x = i;
				Ed[k].y = j;
				k++;
			}
		}
	}

	go(0);
	cout << ans;

}