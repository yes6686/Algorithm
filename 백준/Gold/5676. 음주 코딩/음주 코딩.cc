#include <iostream>
using namespace std;

int arr[100001];
int t[400001];

int init(int n, int s, int e) {
	if (s == e) {
		return t[n] = arr[s];
	}
	else {
		return t[n] = init(2 * n, s, (s + e) / 2) * init(2 * n + 1, (s + e) / 2 + 1, e);
	}
}

int mul(int n, int s, int e, int l, int r) {
	if (r < s || l > e) return 1;
	if (l <= s && e <= r) return t[n];

	return mul(n * 2, s, (s + e) / 2, l, r) * mul(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int modify(int n,int s,int e, int i, long long int diff) {
	
	if (i < s || e < i) return t[n];
	if (s == e) {
		return t[n] = diff;
	}
	if (s != e) {
		return t[n]=modify(2 * n, s, (s + e) / 2, i, diff) * modify(2 * n+1, (s+e)/2+1, e, i, diff);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,x;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x > 0) arr[i] = 1;
			if (x == 0) arr[i] = 0;
			if (x < 0) arr[i] = -1;
		}
		init(1, 0, n - 1);
		char a;
        int b, c;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if (a == 'P') {
				long long int k = mul(1, 0, n - 1, b - 1, c - 1);
				if (k == 0)cout << 0;
				if (k < 0) cout << '-';
				if (k > 0) cout << '+';
			}
			else if (a == 'C') {
				if(c>0) arr[b - 1] = 1;
				if(c==0) arr[b - 1] = 0;
				if(c<0) arr[b - 1] = -1;

				modify(1, 0, n - 1, b - 1, arr[b-1]);
			}
		}
		cout << '\n';
	}
}