#include <iostream>
#include <cstring>
using namespace std;

int arr[10][10];



int c1[10][10];
int c2[10][10];
int c3[10][10];
int squsum[10];
int ex = 0;
string s[10];
int noanswer = 0;

int res[10];
void dfs(int x, int y) {
	if (ex) return;

	if (x == 10 && ex==0) {
		int sum = 0;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				sum += arr[i][j];
				res[arr[i][j]]++;
			}
		}
		int che = 1;
		for (int i = 1; i <= 9; i++) {
			if (res[i] != 9) {
				che = 0;
				break;
			}
		}
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				int k = ((i - 1) / 3) * 3 + ((j - 1) / 3) + 1;
				squsum[k] += arr[i][j];
			}
		}
		for (int i = 1; i <= 9; i++) {
			if (squsum[i] != 45) {
				che = 0;
				break;
			}
		}
		if (sum == 405 && che) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					cout<< arr[i][j];
				}
				cout << '\n';
			}
		}
		else {
			noanswer = 1;
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

	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 9; i++) {
			cin >> s[i];
			for (int j = 0; j <s[i].size(); j++) {
				arr[i+1][j+1] = s[i][j] - '0';
			}
		}
		ex = 0;
		noanswer = 0;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (arr[i][j]) {
					int k = ((i - 1) / 3) * 3 + ((j - 1) / 3) + 1;
					c1[i][arr[i][j]] = 1;
					c2[j][arr[i][j]] = 1;
					c3[k][arr[i][j]] = 1;
				}
			}
		}

		dfs(1, 1);
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		memset(c3, 0, sizeof(c3));
		memset(squsum, 0, sizeof(squsum));
		memset(res, 0, sizeof(res));
		if (ex == 0 || noanswer) {
			cout << "Could not complete this grid."<<'\n';
		}
		cout << '\n';
	}
	
}

