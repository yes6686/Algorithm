#include <iostream>	
#include <cstring>
using namespace std;

int n;

int c[15];
int d1[30];
int d2[30][30];

int ans = 0;
void btk(int x, int y) {

	if (y == n) {
		ans++;
		return;
	}


	c[x] = 1;
	d1[x + y] = 1;

	for (int i = 1; i <= n; i++) {
		d2[x + i][y + i] = 1;
	}
	for (int i = 1; i <= n; i++) {

		if (c[i] == 0 && d1[i+y+1]==0 && d2[i][y+1]==0) {
			c[i] = 1;
			d1[i + y + 1] = 1;
			for (int j = 1; j <= n; j++) {
				d2[i + j][y + 1 + j] = 1;
			}
			btk(i, y + 1);
			c[i] = 0;
			d1[i + y + 1] = 0;
			for (int j = 1; j <= n; j++) {
				d2[i + j][y + 1 + j] = 0;
			}
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		btk(i, 1);
		memset(c, 0, sizeof(c));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
	}
	cout << ans;



}