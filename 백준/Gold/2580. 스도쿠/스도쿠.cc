#include <iostream>
using namespace std;

int arr[10][10];



int c1[10][10];
int c2[10][10];
int c3[10][10];
int ex = 0;
void dfs(int x, int y) {
	if (ex) return;

	if (x == 10) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << arr[i][j]<<' ';
			}
			cout << '\n';
		}
		ex++;
		return;
	}


	if (arr[x][y]) {
		if (y == 9) {
			dfs(x + 1, 1);
		}
		else {
			dfs(x, y + 1);
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (arr[x][y] == 0) {
			if (c1[x][i]) continue;
			if (c2[y][i]) continue;
			if (c3[((x - 1) / 3) * 3 + ((y - 1) / 3) + 1][i]) continue;
			arr[x][y] = i;
			c1[x][i] = 1;
			c2[y][i] = 1;
			c3[((x - 1) / 3) * 3 + ((y - 1) / 3) + 1][i] = 1;
			if (y == 9) {
				dfs(x + 1, 1);
				c1[x][i] = 0;
				c2[y][i] = 0;
				c3[((x - 1) / 3) * 3 + ((y - 1) / 3) + 1][i] = 0;
				arr[x][y] = 0;
			}
			else {
				dfs(x, y + 1);
				c1[x][i] = 0;
				c2[y][i] = 0;
				c3[((x - 1) / 3) * 3 + ((y - 1) / 3) + 1][i] = 0;
				arr[x][y] = 0;
			}
		}
		
		
	}



}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (arr[i][j]) {
				int k = ((i-1) / 3)*3 + ((j-1) / 3)+1;
				c1[i][arr[i][j]] = 1;
				c2[j][arr[i][j]] = 1;
				c3[k][arr[i][j]] = 1;
			}
		}
	}
	
	dfs(1, 1);
	
}

