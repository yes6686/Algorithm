#include <iostream>
using namespace std;

int arr[16];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long int coin = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] < arr[i]) {
			if (coin != 0) continue;
			coin = w / arr[i - 1];
			w %= arr[i - 1];
		}
		else if(arr[i-1] > arr[i]) {
			w += coin * arr[i - 1];
			coin = 0;
		}
	}
	w += coin * arr[n - 1];
	cout << w << '\n';
}