#include <iostream>
using namespace std;

struct edge {
	int x, y;
	int d;
	int live=1;
};

int arr[5][5];

edge Ed[17];
int maxCnt = -1;

int dx[9] = {0,-1,-1,0, 1,  1,1,0, -1    };
int dy[9] = {0,0,-1,-1,-1,  0,1,1, 1   };


void goShark(int (*arr)[5],edge Ed[], int x, int y, int cnt) {


	int carr[5][5];
	edge cEd[17];

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			carr[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		cEd[i] = Ed[i];
	}
	int s = carr[x][y];
	int sd = cEd[s].d;
	cEd[s].live = 0;
	carr[x][y] = -1;
	maxCnt = max(maxCnt, cnt);

	for (int i = 1; i <= 16; i++) {
		int a = cEd[i].x;
		int b = cEd[i].y;
		int di = cEd[i].d;
		if (cEd[i].live == 1) {
			for (int t = 0; t < 8; t++) {
				int k = (di + t) ;
				if (di + t > 8) k -= 8;
				if (a + dx[k] <= 0 || b + dy[k] <= 0 || a + dx[k] > 4
					|| b + dy[k] > 4) continue;
				if (a +dx[k] == x && b+dy[k] == y) continue;
				int a1 = a + dx[k];
				int b1 = b + dy[k];
				if (carr[a1][b1]!=-1) {
					int k1 = carr[a1][b1];

					carr[a1][b1] = i;
					carr[a][b] = k1;

					
					cEd[i].x = a1;
					cEd[i].y = b1;
					cEd[i].d = k;
					
					cEd[k1].x = a;
					cEd[k1].y = b;
				}
				else {
					carr[a1][b1] = i;
					carr[a][b] = -1;
					cEd[i].x = a1;
					cEd[i].y = b1;
					cEd[i].d = k;
				}
				break;
			}
		}
	}
	for (int i = 1; i <= 3; i++) {
		int a2 = x + dx[sd] * i;
		int b2 = y + dy[sd] * i;
		int kk = carr[a2][b2];
		if (a2 <= 0 || b2 <= 0 || a2 > 4 || b2 > 4) break;
		if (carr[a2][b2]!=-1) {

			goShark(carr,cEd,a2, b2, cnt + kk);
		}
	}
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> a >> b;
			Ed[a].x = i;
			Ed[a].y = j;
			Ed[a].d = b;
			arr[i][j] = a;
		}
	}
	goShark(arr,Ed,1, 1, arr[1][1]);
	cout << maxCnt;




}