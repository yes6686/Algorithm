#include <iostream>
#include <vector>
using namespace std;

int arr[31];
int arrp[11];
vector<int>v[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int x;
				cin >> x;
				v[i].push_back(x);
			}
			cin >> arrp[i];
		} 
		for (int i = 0; i < m; i++) {
			cin >> arr[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int minV = 100;
			for (int j = 0; j < v[i].size(); j++) {
				int k = v[i][j]-1;
				if (minV > arr[k]) {
					minV = arr[k];
				}
			}
			ans += (arrp[i] * minV);
		}
		
		for (int i = 0; i < n; i++) {
			v[i].clear();
		}
		cout << ans << '\n';
	}
}