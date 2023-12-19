#include <iostream>
using namespace std;

unsigned long long int c[201][201];

unsigned long long int combination(long long int n, long long int r) {
	if (n == r || r == 0) return 1;
	if (c[n][r]) return c[n][r];
	return c[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

long long int n, m, k;

void dfs(int n, int m,int k) {

	if (n == 0 && m == 0) {
		return;
	}
	if (n == 0) {
		cout << 'z';
		dfs(n, m-1, k);
		return;
	}
	if (m == 0) {
		cout << 'a';
		dfs(n-1, m, k);
		return;
	}



	if (combination(n+m-1,m) >= k) {
		cout << 'a';
		dfs(n - 1, m, k);
		return;
	}
	else {
		cout << 'z';
		dfs(n, m - 1, k- combination((n - 1) + m, m));
		return;
	}
	

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	if (k > combination(n + m, n)) {
		cout << -1 << '\n';
	}
	else {
		dfs(n, m, k);
	}
}
