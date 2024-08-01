#include <iostream>
#include <algorithm>
using namespace std;

int arrn[100001];
int arrh[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arrn[i];
		ans += arrn[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arrh[i];
	}
	sort(arrh, arrh + n);
	for (int i = 0; i < n; i++) {
		ans += (arrh[i] * i);
	}
	cout << ans;
}