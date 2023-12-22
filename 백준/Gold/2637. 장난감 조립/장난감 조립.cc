#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int dp[MAX][MAX];
int arr[MAX][MAX];
int inDegree[MAX];
vector<int>v[MAX];
queue<int>q;
int check[MAX];
int main() {

	int n;
	cin >> n;
	int m;
	cin >> m;
	int x, y, k;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> k;
		v[y].push_back(x);
		check[x] = 1;
		inDegree[x]++;
		arr[y][x] = k;
	}
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		int k = q.front();
		q.pop();
		for (int j = 0; j < v[k].size(); j++) {
			int h = v[k][j];
			inDegree[h]--;
			if (check[k] == 1) {
				for (int a = 1; a < n; a++) {
					dp[h][a] +=dp[k][a] * arr[k][h];
				}
			}
			else {
				dp[h][k] +=arr[k][h];
			}
			if (inDegree[h] == 0) {
				q.push(h);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if(dp[n][i])
		cout << i << ' ' << dp[n][i] << '\n';
	}
	
}