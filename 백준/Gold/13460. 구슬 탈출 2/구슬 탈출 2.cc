#include <iostream>
#include <vector>
using namespace std;

string s[11];
vector<vector<int>>V;

vector<int>v1[11];
int minCnt = 11;

void go(int x1, int y1,int x2,int y2, int k,vector<vector<int>>v,int cnt) {
	if (cnt == 11) {
		return;
	}
	if (minCnt <= cnt) {
		return;
	}


	if (k == 1) { // 하
		int check = 0;
		int x1i;
		int y1j;
		int x2i;
		int y2j;
		for (int i = 1; i <= 10; i++) {
			if (v[x1 + i][y1] == 1) {
				v[x1][y1] = 0;
				v[x1 + i - 1][y1] = 2;
				x1i = x1 + i - 1;
				y1j = y1;
				break;
			}
			else if (v[x1 + i][y1] == 100) {
				check++;
				break;
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (v[x2 + i][y2] == 1) {
				v[x2][y2] = 0;
				v[x2 + i - 1][y2] = 3;
				x2i = x2 + i - 1;
				y2j = y2;
				break;
			}
			else if (v[x2 + i][y2] == 100) {
				check=100;
				break;
			}
		}

		if (check == 0) {
			if (x1i == x2i && y1j == y2j) {
				if (x1 > x2) {
					x2i -= 1;
				}
				else {
					x1i -= 1;
				}
			}
		}

		if (check == 100) {
			return;
		}
		else if(check==1){
			minCnt = min(minCnt, cnt);
			return;
		}
		else {
			go(x1i, y1j, x2i, y2j, 2, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 3, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 4, v, cnt + 1);
			return;
		}


	}
	else if (k == 2) { // 상
		int check = 0;
		int x1i;
		int y1j;
		int x2i;
		int y2j;
		for (int i = 1; i <= 10; i++) {
			if (v[x1 - i][y1] == 1) {
				v[x1][y1] = 0;
				v[x1 - i + 1][y1] = 2;
				x1i = x1 - i + 1;
				y1j = y1;
				break;
			}
			else if (v[x1 - i][y1] == 100) {
				check++;
				break;
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (v[x2 - i][y2] == 1) {
				v[x2][y2] = 0;
				v[x2 - i + 1][y2] = 3;
				x2i = x2 - i + 1;
				y2j = y2;
				break;
			}
			else if (v[x2 - i][y2] == 100) {
				check = 100;
				break;
			}
		}

		if (check == 0) {
			if (x1i == x2i && y1j == y2j) {
				if (x1 > x2) {
					x1i += 1;
				}
				else {
					x2i += 1;
				}
			}
		}


		if (check == 100) {
			return;
		}
		else if (check == 1) {
			minCnt = min(minCnt, cnt);
			return;
		}
		else {
			go(x1i, y1j, x2i, y2j, 1, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 3, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 4, v, cnt + 1);
			return;
		}
	}
	else if (k == 3) { // 좌
		int check = 0;
		int x1i;
		int y1j;
		int x2i;
		int y2j;
		for (int i = 1; i <= 10; i++) {
			if (v[x1 ][y1-i] == 1) {
				v[x1][y1] = 0;
				v[x1][y1-i+1] = 2;
				x1i = x1;
				y1j = y1-i+1;
				break;
			}
			else if (v[x1][y1-i] == 100) {
				check++;
				break;
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (v[x2 ][y2-i] == 1) {
				v[x2][y2] = 0;
				v[x2 ][y2-i+1] = 3;
				x2i = x2 ;
				y2j = y2-i+1;
				break;
			}
			else if (v[x2][y2-i] == 100) {
				check = 100;
				break;
			}
		}

		if (check == 0) {
			if (x1i == x2i && y1j == y2j) {
				if (y1 > y2) {
					y1j += 1;
				}
				else {
					y2j += 1;
				}
			}
		}


		if (check == 100) {
			return;
		}
		else if (check == 1) {
			minCnt = min(minCnt, cnt);
			return;
		}
		else {
			go(x1i, y1j, x2i, y2j, 1, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 2, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 4, v, cnt + 1);
			return;
		}
	}
	else if (k == 4) { // 우
		int check = 0;
		int x1i;
		int y1j;
		int x2i;
		int y2j;
		for (int i = 1; i <= 10; i++) {
			if (v[x1][y1 + i] == 1) {
				v[x1][y1] = 0;
				v[x1][y1 + i - 1] = 2;
				x1i = x1;
				y1j = y1 + i - 1;
				break;
			}
			else if (v[x1][y1 + i] == 100) {
				check++;
				break;
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (v[x2][y2 + i] == 1) {
				v[x2][y2] = 0;
				v[x2][y2 + i - 1] = 3;
				x2i = x2;
				y2j = y2 + i - 1;
				break;
			}
			else if (v[x2][y2 + i] == 100) {
				check = 100;
				break;
			}
		}

		if (check == 0) {
			if (x1i == x2i && y1j == y2j) {
				if (y1 > y2) {
					y2j -= 1;
				}
				else {
					y1j -= 1;
				}
			}
		}


		if (check == 100) {
			return;
		}
		else if (check == 1) {
			minCnt = min(minCnt, cnt);
			return;
		}
		else {
			go(x1i, y1j, x2i, y2j, 1, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 2, v, cnt + 1);
			go(x1i, y1j, x2i, y2j, 3, v, cnt + 1);
			return;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int redi;
	int redj;
	int bluei;
	int bluej;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				v1[i].push_back(1);
			}
			else if (s[i][j] == '.') {
				v1[i].push_back(0);
			}
			else if (s[i][j] == 'R') {
				v1[i].push_back(2);
				redi = i;
				redj = j;
			}
			else if (s[i][j] == 'B') {
				v1[i].push_back(3);
				bluei = i;
				bluej = j;
			}
			else if (s[i][j] == 'O') {
				v1[i].push_back(100);
			}	
		}
		V.push_back(v1[i]);

	}
	go(redi, redj, bluei, bluej, 1, V, 1);
	go(redi, redj, bluei, bluej, 2, V, 1);
	go(redi, redj, bluei, bluej, 3, V, 1);
	go(redi, redj, bluei, bluej, 4, V, 1);
	if (minCnt == 11) cout << -1 << '\n';
	else
	cout << minCnt << '\n';

}