#include <iostream>
using namespace std;

int arr[9][9];
int kx, ky, tx, ty;

void solve(int nx,int ny) {

	int kcx = kx + nx;
	int kcy = ky + ny;
	int tcx = tx;
	int tcy = ty;

	if (kcx == tx && kcy == ty) {
		tcx += nx;
		tcy += ny;
	}
	if (kcx > 8 || kcy > 8 || kcx < 1 || kcy < 1) return;
	if (tcx > 8 || tcy > 8 || tcx < 1 || tcy < 1) return;

	kx = kcx;
	ky = kcy;
	tx = tcx;
	ty = tcy;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string k, t;
	int n;
	cin >> k >> t >> n;

	kx = k[0] - 'A' + 1;
	ky = k[1] - '0';

	tx = t[0] - 'A' + 1;
	ty = t[1] - '0';

	for (int i = 0; i < n; i++) {
		string m;
		cin >> m;
		if (m == "R") { // 한 칸 오른쪽
			solve(1, 0);
		}
		else if (m == "L") { // 한 칸 왼쪽
			solve(-1, 0);
		}
		else if (m == "B") { // 한 칸 아래로
			solve(0, -1);
		}
		else if (m == "T") { // 한 칸 위로
			solve(0, 1);
		}
		else if (m == "RT") { // 오른쪽 위 대각선
			solve(1, 1);
		}
		else if (m == "LT") { // 왼쪽 위 대각선
			solve(- 1, 1);
		}
		else if (m == "RB") { // 오른쪽 아래 대각선
			solve(1, -1);
		}
		else if (m == "LB") { // 왼쪽 아래 대각선
			solve(-1, -1);
		}

	}
	char kkx = kx + 'A'-1;
	char ttx = tx + 'A'-1;
	cout << kkx << ky<<'\n';
	cout << ttx << ty<<'\n';

}