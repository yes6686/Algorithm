#include <iostream>
#include <stack>
using namespace std;

long long int arr[100001];

stack<pair<long long int, long long int>>st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		st.push({ arr[0],0 });
		long long int ans = 0;
		for (int i = 1; i < n; i++) {
			long long int vv, vi = i;
			while (!st.empty()) {
				if (st.top().first > arr[i]) {
					vi = st.top().second;
					vv = st.top().first;
					ans = max(ans, vv * (i - vi));
					st.pop();
				}
				else{
					break;
				}
			}
			st.push({ arr[i],vi });
		}
		while (!st.empty()) {
			ans = max(ans, (st.top().first * (n - st.top().second)));
			st.pop();
		}
		cout << ans << '\n';
	}
}