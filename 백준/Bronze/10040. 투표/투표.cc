#include <iostream>
using namespace std;

int cost[1001];
int pr[1001];

int vote[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> pr[i];
	}

	for (int i = 0; i < m; i++) {
		int v = pr[i];
		for (int j = 0; j < n; j++) {
			if (v >= cost[j]) {
				vote[j+1]++;
				break;
			}
		}
	}
	int maxIndex = 0;
	int ans;
	for (int i = 0; i < n; i++) {
		if (maxIndex < vote[i]) {
			maxIndex = vote[i];
			ans = i;
		}
	}
	cout << ans;
}