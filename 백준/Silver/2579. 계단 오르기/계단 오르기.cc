#include <iostream>
using namespace std;
int arr[301];
int st[301];

int dp(int n){
	if (n < 0) return 0;
	if (n == 1) return arr[n] = st[n];
	if (n == 2) return arr[n] = st[n] + st[n - 1];
	if (arr[n] != 0) return arr[n];
	else {
		return arr[n] = max(st[n - 1] +dp(n-3),
			dp(n-2))+st[n];
	}

}

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> st[i];
	}
	cout << dp(n);

}