#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int ans[1000001];

stack<pair<int, int>>st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[i] = -1;
	}
	st.push({ 0,arr[0] });
	for (int i = 1; i < n; i++) {
		if (st.top().second >= arr[i]) {
			st.push({ i,arr[i] });
		}
		else {
			while (!st.empty()) {
				if (st.top().second >= arr[i]) break;
				ans[st.top().first] = arr[i];
				st.pop();
			}
			st.push({ i,arr[i] });
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}