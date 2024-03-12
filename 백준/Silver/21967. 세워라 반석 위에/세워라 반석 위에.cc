//3
#include <iostream>
#include <deque>
using namespace std;

int arr[11];
deque<int>dq;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int maxAns = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
		dq.push_back(x);
		while (!dq.empty()) {
			int minV = 11;
			int maxV = 1;
			for (int j = 1; j <= 10; j++) {
				if (arr[j]) {
					minV = min(minV, j);
					maxV = max(maxV, j);
				}
			}
			if (maxV - minV <= 2) {
				break;
			}
			int f = dq.front();
			dq.pop_front();
			arr[f]--;
		}
		if (maxAns < dq.size()) {
			maxAns = dq.size();
		}
	}
	cout << maxAns;
	
}