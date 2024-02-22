#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[1001];
int narr[1001];

queue<int>q;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			narr[arr[i]]++;
			if (narr[arr[i]] == 6) {
				q.push(arr[i]);
			}
		}
		pair<int, int> maxAns; // maxSum, lastValue
		maxAns.first = 1e9;
		maxAns.second = 1e9;
		int winTeam = 1;
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			int sum = 0;
			int s = 1;
			int lastValue = 1;
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (k == arr[i] && cnt<4) {
					sum += s;
					lastValue = s;
					cnt++;
				}
				else if (k == arr[i] && cnt == 4) {
					lastValue = s;
					cnt++;
				}
				if (narr[arr[i]] == 6) s++;
			}
			if (maxAns.first > sum) {
				maxAns.first = sum;
				maxAns.second = lastValue;
				winTeam = k;
			}
			if (maxAns.first == sum) {
				if (maxAns.second > lastValue) {
					maxAns.second = lastValue;
					winTeam = k;
				}
			}			
		}
		cout << winTeam<< '\n';
		memset(narr, 0, sizeof(narr));
	}
}