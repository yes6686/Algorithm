#include <iostream>
using namespace std;

long long int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n, m;
	cin >> n >> m;
	for (long long int i = 2; i * i <= m; i++) {
		long long int k = n / (i * i);
		if (n % (i * i)) k++;

		for (long long int j = k*(i*i); j <= m; j += (i*i)) {
			arr[j - n] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= m-n; i++) {
		if (!arr[i]) {
			ans++;
		}
	}
	cout << ans;
}