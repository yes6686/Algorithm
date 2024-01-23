#include <iostream>
using namespace std;

int arr[21];
int n, s;
int ans = 0;

void solve(int depth, int a) {
	if (depth == n) return;
	if (a + arr[depth] == s) ans++;
	solve(depth + 1, a + arr[depth]);
	solve(depth + 1, a );
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i< n; i++) {
		cin >> arr[i];
	}
	solve(0, 0);
	cout << ans;
}