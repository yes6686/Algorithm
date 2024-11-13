#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int m, k;
	cin >> m >> k;
	int t = m * k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++) {
		t -= arr[i];
		ans++;
		if (t <= 0) {
			break;
		}
	}
	if (t > 0){
		cout << "STRESS" << '\n';
	}
	else {
		cout << ans;
	}
}