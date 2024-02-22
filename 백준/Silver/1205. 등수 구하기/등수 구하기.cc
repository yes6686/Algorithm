#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];
int sarr[51];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, s, p;
	cin >> n >> s >> p;
	if (n == 0) {
		cout << 1<<'\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr[n] = s;

	sort(arr, arr + n + 1,compare);

	sarr[0] = 1;

	int k = 1;
	int ans = 1;
	int c = 0;

	for (int i = 1; i <= n; i++) {

		if (arr[i - 1] != arr[i]) {
			sarr[i] = sarr[i - 1] + 1;
			sarr[i] += c;
			c = 0;
		}
		else {
			sarr[i] = sarr[i - 1];
			c++;
		}
		if (arr[i] == s) {
			k = i + 1;
			ans = sarr[i];
		}
	}
	if (k <= p) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}