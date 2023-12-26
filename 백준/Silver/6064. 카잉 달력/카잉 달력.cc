#include <iostream>
using namespace std;


int arr[40001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int m, n, x, y;
	int t = 1;
	while (T--) {
		cin >> m >> n >> x >> y;
		int k = x;
		while (1) {
			if (arr[k % n] == t) {
				cout << -1 << '\n';
				break;
			}
			else if (k % n == y || (n==y && k%n==0)) {
				cout << k << '\n';
				break;
			}
			else {
				arr[k % n]=t;
			}
			k += m;
		}
		t++;
	}
}