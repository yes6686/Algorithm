#include <iostream>
#include <algorithm>
using namespace std;

int arrn[100001];
int arrh[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n < 10) {
			cout << 1 << '\n';
			continue;
		}
		int cnt = 0;
		while (true) {
			int check = 0;
			for (int i = 9; i >= 2; i--) {
				if (n % i == 0) {
					n /= i;
					cnt++;
					check = 1;
					break;
				}
			}
			if (n < 10) {
				cnt++;
				break;
			}
			else {
				if (check == 0) {
					cnt = -1;
					break;
				}
			}
		}
		cout << cnt<<'\n';
	}
}