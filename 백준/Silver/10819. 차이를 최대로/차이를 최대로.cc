#include <iostream>
#include <cmath>
using namespace std;

int arr[9];
int carr[9];
int visited[9];
int n;
int maxAns = 0;

void sol(int d) {
	if (d == n) {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum += abs(carr[i - 1] - carr[i]);
		}
		maxAns = max(maxAns, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			carr[d] = arr[i];
			sol(d + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		carr[i] = arr[i];
	}
	sol(0);
	cout << maxAns;
}