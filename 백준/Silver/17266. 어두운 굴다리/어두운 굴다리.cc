#include <iostream>
using namespace std;

int arr[1000001];

int main() {
   
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int prex = 0;
	int minH = 0;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (i == 0) {
			if (x != 0) {
				minH = max(minH, x - prex);
			}
		}
		else {
			minH = max(minH, (x - prex) / 2 + (x - prex) % 2);
		}

		prex = x;
	}
	if (prex != n) {
		minH = max(minH, n - prex);
	}
	cout << minH;

}