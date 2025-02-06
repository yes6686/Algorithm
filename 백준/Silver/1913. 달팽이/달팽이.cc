#include <iostream>
using namespace std;

int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int k;
	cin >> k;
	// 3->1 , 1->4, 4->2 , 2->3
	int d = 3; 

	int s = n * n;
	int x = 0;
	int y = 0;
	int m = 1;
	int ansX, ansY;
	while (true) {

		arr[x][y] = s;
		if (s == k) {
			ansX = x;
			ansY = y;
		}
		if (s == 1) break;
		if (d == 1) {
			y += 1;
			if (arr[x][y]) {
				y -= 1;
				d = 4;
				m = 1;
				continue;
			}
		}
		else if (d == 2) {
			y -= 1;
			if (arr[x][y]) {
				y += 1;
				d = 3;
				m = 1;
				continue;
			}
		}
		else if (d == 3) {
			x += 1;
			if (arr[x][y]) {
				x -= 1;
				d = 1;
				m = 1;
				continue;
			}
		}
		else {
			x -= 1;
			if (arr[x][y]) {
				x += 1;
				d = 2;
				m = 1;
				continue;
			}
		}

		s--;
		m++;
		if (m > n) {
			m = 2;
			if (d == 1) {
				d = 4;
				y -= 1;
				x -= 1;
			}
			else if (d == 2) {
				d = 3;
				y += 1;
				x += 1;
			}
			else if (d == 3) {
				d = 1;
				x -= 1;
				y += 1;
			}
			else {
				d = 2;
				x += 1;
				y -= 1;
			}
		}

	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ansX+1 << " " << ansY+1 << '\n';
}