#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>>st;
int arr[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st.push({1,arr[0]});
	cout << 0 << ' ';
	for (int i = 1; i < n; i++) {
		while (!st.empty()) {
			if (st.top().second >= arr[i]) {
				cout << st.top().first << ' ';
				st.push({ i + 1,arr[i] });
				break;
			}
			else {
				st.pop();
			}
		}
		if (st.size() == 0) {
			cout << 0 << ' ';
			st.push({ i + 1,arr[i] });
		}
	}
}