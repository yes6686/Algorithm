#include <iostream>
using namespace std;

int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a;j < a + c;j++) {
			for (int h = b;h < b + d;h++) {
				arr[j][h] = i;
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		int cnt = 0;

		for (int j = 0;j <= 1000;j++) {
			for (int h = 0;h <= 1000;h++) {
				if (arr[j][h] == i) {
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}	
}