#include <iostream>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		arr[a]++;
		arr[b]++;
	}

	for (int i = 1;i <= n;i++) {
		cout << arr[i] << '\n';
	}
}