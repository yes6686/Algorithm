#include <iostream>
#include <set>
using namespace std;

int rowCnt[100001];
int colCnt[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n + m; i++) {
		cin >> x >> y;
		rowCnt[x]++;
		colCnt[y]++;
	}
	for (int i = 0; i < 100001; i++) {
		if (rowCnt[i] % 2 == 1 || colCnt[i] % 2 == 1) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}