#include <iostream>
using namespace std;

int arr[100001];
int sum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n ,m;
	cin >> n >>m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}
	int i, j;
	while (m--) {
		cin >> i >> j;
		cout << sum[j] - sum[i-1]<<'\n';
	}	
}