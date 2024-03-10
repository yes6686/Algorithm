#include <iostream>
using namespace std;

int arr[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int s = 0;
	int e = 0;
	int t = 0;
	int maxAns = 0;
	while (e<n) {
		if (t<=m) {
			t += arr[e];
			e++;
			if(t<=m)
				maxAns = max(maxAns, t);
		}
		else {

			t -= arr[s];
			if (t <= m)
				maxAns = max(maxAns, t);
			if (s < e) {
				s++;
			}
			else {
				e++;
			}
		}
	}
	cout << maxAns;
}