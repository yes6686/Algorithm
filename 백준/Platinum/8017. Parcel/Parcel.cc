#include <iostream>
#include <stack>
using namespace std;

int arrR[2001][2001];
int arr[2001][2001];

stack<pair<int,int>>st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (i == 0) {
				if (arr[i][j] == 0) {
					arrR[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[j][i] == 0) {
				arrR[j][i] = arrR[j - 1][i] + 1;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		while (!st.empty()) st.pop();
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {

				while (!st.empty()) {
					ans = max(ans, st.top().first * (j - st.top().second));
					st.pop();
				}
			}
			else {
				if (st.size() == 0) {
					st.push({ arrR[i][j],j });
					ans = max(ans, arrR[i][j]);
				}
				else {
					int v, vi = j;
					while (!st.empty()) {
						if (st.top().first > arrR[i][j]) {
							v = st.top().first;
							vi = st.top().second;
							st.pop();
							ans = max(ans, v * (j - vi));
						}
						else {
							break;
						}
					}
					st.push({ arrR[i][j],vi });

				}
			}
		}
	}
	cout << ans << '\n';	
}