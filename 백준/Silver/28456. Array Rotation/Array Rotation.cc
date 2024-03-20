#include <iostream>
using namespace std;

int arr[101][101];
int t[101][101];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x == 1) {
			int y;
			cin >> y;
			int tmp = arr[y][n];
			for (int i = n; i >1; i--) {
				arr[y][i] = arr[y][i - 1];
			}
			arr[y][1] = tmp;
		}
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					t[j][n - i + 1] = arr[i][j];
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					arr[i][j] = t[i][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}