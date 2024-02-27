#include <iostream>
#include <algorithm>
using namespace std;

int arr[20001];
int s[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			s[i] = arr[i];
		}
		else {
			s[i] = s[i - 1] + arr[i];
		}
	}

	int minAns = 2e9;
	int ans = 0;
	for (int i = 0; i < n; i++) {

		int left = 0;
		if(i!=0)
			left = (arr[i]*i) - s[i - 1];
		int right = (s[n - 1] - s[i])- ((n-1-i)*arr[i]);
		if (minAns > left + right) {
			minAns = left + right;
			ans = arr[i];
		}
	}
	cout << ans;
}