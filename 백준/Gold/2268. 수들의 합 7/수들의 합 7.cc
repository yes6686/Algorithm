#include <iostream>
using namespace std;

int arr[1000001];
long long int t[3000001];

long long int sum(int n, int s, int e,int l,int r) {
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) return t[n];

	return sum(n*2, s, (s + e) / 2, l, r) + sum(n*2+1, (s + e) / 2 + 1, e, l, r);
}

void modify(int n,int s,int e, int i, int diff) {
	if (i < s || e < i) return;
	t[n] += diff;
	if (s != e) {
		modify(2 * n, s, (s + e) / 2, i, diff);
		modify(2 * n+1, (s+e)/2+1, e, i, diff);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n>>m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0) { // sum 함수를 리턴
			if (b < c) {
				cout << sum(1, 0, n - 1, b-1, c-1) << '\n';
			}
			else{
				cout << sum(1, 0, n - 1, c-1, b-1) << '\n';
			}
		}
		else if(a == 1){ // modify(b, c)를 수행
			int d = c - arr[b-1];
			arr[b-1] = c;
			modify(1, 0, n - 1, b-1, d);
		}
	}
}