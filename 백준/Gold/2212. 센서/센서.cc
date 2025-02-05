#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int arr[10001];

set<int>st;
vector<pair<int,int>>v;
vector < pair<int, int>>vt;
int check[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int k;
	cin >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		st.insert(arr[i]);
	}
	if (n <= k) {
		cout << 0 << '\n';
		return 0;
	}

	set<int>::iterator iter;
	int s = 0;
	for (iter = st.begin(); iter != st.end(); iter++) {
		arr[s++] = *iter;
	}
	for (int i = 0; i < s-1; i++) {
		vt.push_back({ arr[i + 1] - arr[i],i });
	}

	sort(vt.rbegin(), vt.rend());

	for (int i = 0; i < k - 1; i++) {
		check[vt[i].second] = 1;
	}
	int ans = 0;
	for (int i = 0; i < s-1; i++) {
		if (check[i] == 0) {
			ans += arr[i+1]-arr[i];
		}
	}
	cout << ans<<'\n';

}