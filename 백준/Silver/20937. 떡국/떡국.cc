#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int cnt[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
		ans = max(ans, cnt[arr[i]]);
	}
	cout << ans;
}