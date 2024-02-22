#include <iostream>
using namespace std;

int arr[101][101];

int main() {
	int x1, y1, x2, y2;
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int t = y1; t < y2; t++) {
				arr[j][t] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j]) ans++;
		}
	}
	cout << ans;
}