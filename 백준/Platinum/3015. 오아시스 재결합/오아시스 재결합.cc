#include <iostream>
#include <stack>
using namespace std;

int arr[500001];
stack<pair<int,int>>st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st.push({ arr[0],1 });
	for (int i = 1; i < n; i++) {
		int d = 1;
		if (st.top().first <= arr[i]) {
			while (!st.empty()) {
				if (st.top().first > arr[i]) break;
				if (st.top().first == arr[i]) {
					ans += st.top().second;
					d = st.top().second + 1;
				}
				else {
					ans += st.top().second;
					d = 1;
				}

				st.pop();
			}
		}
		if (st.size()) ans++;
		st.push({ arr[i],d });
	}
	cout << ans;
}