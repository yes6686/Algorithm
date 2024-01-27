#include <iostream>
#include <stack>
using namespace std;

int arr[1001];
int dp[1001];

stack<int>s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	int maxAns = 1;
	int maxLastIndex = n -1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				if (maxAns < dp[i]) {
					maxAns = dp[i];
					maxLastIndex = i;
				}
			}
		}
	}
	cout << maxAns << '\n';
	s.push(arr[maxLastIndex]);
	for (int i = maxLastIndex-1; i >= 0; i--) {
		if (arr[maxLastIndex] > arr[i] && dp[maxLastIndex] == dp[i] + 1) {
			s.push(arr[i]);
			maxLastIndex = i;
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}