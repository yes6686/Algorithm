#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int arr[101][101];
string dp[101][101];

int n;

void reverse(string &a) {
	for (int i = 0; i < a.size()/2; i++) {
		char temp = a[i];
		a[i] = a[a.size() - i - 1];
		a[a.size() - i - 1] = temp;

	}
}
string add(string a, string b) {
	for (int i = 0; i < a.size() / 2; i++) {
		char temp = a[i];
		a[i] = a[a.size() - i - 1];
		a[a.size() - i - 1] = temp;

	}
	for (int i = 0; i < b.size() / 2; i++) {
		char temp = b[i];
		b[i] = b[b.size() - i - 1];
		b[b.size() - i - 1] = temp;

	}
	string result = "";
	int len; int carry = 0;
	if (a.size() > b.size()) {
		len = a.size();
	}
	else {
		len = b.size();
	}
	for (int i = 0; i < len; i++) {
		int sum = 0;
		if (i < a.size()) {
			sum += a[i] - '0';
		}
		if (i < b.size()) {
			sum += b[i] - '0';
		}
		sum += carry;
		if (sum < 0) {
			sum += '0';
		}
		if (sum >= 10) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		result += (sum % 10 + '0');
	}
	if (carry == 1) {
		result += '1';
	}
	reverse(result);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = "0";
		}
	}
	dp[0][0] = "1";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1) continue;
			if (dp[i][j] == "0") continue;
			if (i + arr[i][j] < n) {
				dp[i + arr[i][j]][j] = add(dp[i][j], dp[i + arr[i][j]][j]);
			}
			if (j + arr[i][j] < n) {
				dp[i][j + arr[i][j]] = add(dp[i][j], dp[i][j + arr[i][j]]);
			}
		}
	}
	cout << dp[n-1][n-1];
}