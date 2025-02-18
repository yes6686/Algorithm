#include <iostream>
#include <stack>
using namespace std;

long long int arr[100001];

stack<pair<long long int, long long int>>st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	st.push({ arr[0],0 });
	long long int ans1 = 0;
	long long int ansx = 1;
	long long int ansy = 1;
	for (int i = 1; i < n; i++) {
		long long int vv, vi = i;
		while (!st.empty()) {
			long long int k = 0;
			if (st.top().first > arr[i]) {
				vi = st.top().second;
				vv = st.top().first;
				for (int j = st.top().second; j < i; j++) {
					k += arr[j];
				}
				if (ans1 < k * vv) {
					ansx = st.top().second + 1;
					ansy = i;
					ans1 = k * vv;
				}
				st.pop();
			}
			else{
				break;
			}
		}
		st.push({ arr[i],vi });
	}
	while (!st.empty()) {
		long long int k = 0;
		for (int i = st.top().second; i < n; i++) {
			k += arr[i];
		}

		if (ans1 < k * st.top().first) {
			ansx = st.top().second + 1;
			ansy = n;
			ans1 = k * st.top().first;
		}
		st.pop();
	}
	cout << ans1 << '\n';
	cout << ansx << " " << ansy << '\n';
	
}