#include <iostream>
#include <vector>
using namespace std;

vector<int>v[1000001];
int dp[1000001][2];
int c[1000001];



void con(int x) {
	c[x] = 1;
	dp[x][0] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		if (c[k] == 0) {
			con(k);
			dp[x][0] += min(dp[k][0], dp[k][1]);
			dp[x][1] += dp[k][0];
		}

	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	con(1);
	
	cout << min(dp[1][0], dp[1][1]);


}