#include <iostream>
using namespace std;

int d[20000001];
int arr[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <0) {
			d[( ( - 1) * arr[i]) + 10000000]++;
		}
		else {
			d[arr[i]]++;
		}
	}
	cin >> m;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (x < 0) {
			cout << d[((-1) * x) + 10000000] << ' ';
		}
		else {
			cout << d[x] << ' ';
		}
	}
}