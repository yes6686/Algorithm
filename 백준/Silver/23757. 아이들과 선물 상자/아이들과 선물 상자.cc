#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[100001];
priority_queue<int>pq;


bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		int k = pq.top();
		pq.pop();
		if (k >= arr[i]) {
			k -= arr[i];
			pq.push(k);
		}
		else {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}