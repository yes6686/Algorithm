#include <iostream>
#include <queue>
using namespace std;

int arr[1501][1501];

priority_queue<pair<int,pair<int,int>>>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (i == n - 1) pq.push({ arr[i][j],{i,j} });
		}
	}
	int cnt = 0;
	while (!pq.empty()) {

		int k = pq.top().first;
		int i = pq.top().second.first;
		int j = pq.top().second.second;
		pq.pop();
		cnt++;
		if (cnt == n) {
			cout << k << '\n';
			break;
		}
		else {
			if (i != 0) {
				pq.push({ arr[i - 1][j],{i - 1,j} });
			}
		}
	}
}