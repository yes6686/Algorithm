#include <iostream>
#include <stack>
using namespace std;

stack<int>st;
int arr[80001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st.push(arr[0]);
	long long int ans = 0;
	for (int i = 1; i < n; i++) {
		if (st.top() > arr[i]) {
			ans += st.size();
			st.push(arr[i]);
		}
		else {
			while (!st.empty()) {
				if (st.top() > arr[i]) {
					ans += st.size();
					break;
				}
				st.pop();
			}
			st.push(arr[i]);
		}
	}
	cout << ans;
	
}