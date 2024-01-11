#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] += (arr[i]+dp[i-1]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += dp[i];
	}
	cout << sum;
}