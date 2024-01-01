#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

struct Seg{
	int ma;
	int mi;
};

Seg seg[400001];

Seg go(int n, int s, int e) {
	if (s == e) {
		seg[n].ma = arr[s];
		seg[n].mi = arr[s];
		return seg[n];
	}
	else {
		int mid = (s + e) / 2;
		Seg left = go(2 * n, s, mid);
		Seg right = go(2 * n + 1, mid + 1, e);
		seg[n].ma = max(left.ma, right.ma);
		seg[n].mi = min(left.mi, right.mi);
	//	cout << n << " : " << seg[n].ma << " : " << seg[n].mi << '\n';
		return seg[n];
	}
}
Seg ans;
Seg fi(int n, int s, int e, int l, int r) {
	if (e < l || r < s) return ans;
	if (l <= s && r >= e) {
		return seg[n];
	}
	int mid = (s + e) / 2;
    Seg left = fi(n * 2, s, mid, l, r);
	Seg right = fi(n * 2+1, mid+1, e, l, r);
	ans.ma= max(left.ma, right.ma);
	ans.mi = min(left.mi, right.mi);
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	go(1, 0, n - 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ans.ma = 0;
		ans.mi = 1000000000;
		cout<<fi(1, 0, n - 1, a-1, b-1).mi<<" " << fi(1, 0, n - 1, a-1, b-1).ma << '\n';
		
	}
}