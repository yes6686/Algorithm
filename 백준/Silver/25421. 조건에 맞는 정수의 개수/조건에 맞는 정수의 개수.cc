#include <iostream>
#define MOD 987654321
using namespace std;

long long int arr[10];
long long int carr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n == 1) {
		cout << 9;
		return 0;
	}
	for (int i = 1; i <= 9; i++) {
		arr[i] = 1;
	}
	long long int ans = 0;
	for (int t = 2; t <= n; t++) {
		for (int i = 1; i <= 9; i++) {
			carr[i] = arr[i];
			carr[i] %= MOD;
			arr[i] = 0;
		}
		for (int i = 1; i <= 9; i++) {

			if (i == 1) {
				arr[i] += carr[i];
				arr[i + 1] += carr[i];
				arr[i + 2] += carr[i];
			}
			else if (i == 2) {
				arr[i - 1] += carr[i];
				arr[i] += carr[i];
				arr[i + 1] += carr[i];
				arr[i + 2] += carr[i];
			}
			else if (i >= 3 && i <= 7) {
				arr[i - 2] += carr[i];
				arr[i - 1] += carr[i];
				arr[i] += carr[i];
				arr[i + 1] += carr[i];
				arr[i + 2] += carr[i];
			}
			else if (i == 8) {
				arr[i - 2] += carr[i];
				arr[i - 1] += carr[i];
				arr[i] += carr[i];
				arr[i + 1] += carr[i];
			}
			else {
				arr[i - 2] += carr[i];
				arr[i - 1] += carr[i];
				arr[i] += carr[i];
			}
			arr[i] %= MOD;
			if(i-2>=1)
			arr[i-2] %= MOD;
			if (i - 1 >= 1)
			arr[i-1] %= MOD;
			if(i+1<=9)
			arr[i+1] %= MOD;
			if(i+2<=9)
			arr[i+2] %= MOD;
		}
		
	}
	for (int i = 1; i <= 9; i++) {
		ans += arr[i];
		ans %= MOD;
	}
	cout << ans;

}