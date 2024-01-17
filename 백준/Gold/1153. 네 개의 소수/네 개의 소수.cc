#include <iostream>
using namespace std;

int arr[1000001];

int p[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)arr[i] = i;
	for (int i = 2; i * i <= n; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= n; j += i) {
			arr[j] = 0;
		}
	}
	int s = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			p[s++] = i;
		}
	}
	for (int i = 0; i < s; i++) {
		for (int j = i; j < s; j++) {
			for (int t = j; t < s; t++) {
				for (int h = t; h < s; h++) {
					if (n == p[i] + p[j] + p[t] + p[h]) {
						cout << p[i] << ' ' << p[j] << ' ' << p[t] << ' ' << p[h];
						return 0;
					}
					if (n < p[i] + p[j] + p[t] + p[h]) break;
				}
			}
		}
	}
	cout << -1;
}