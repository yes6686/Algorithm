#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>v[10001];
vector<int>v1[10001];
int w[10001];
int w1[10001];
int max1 = -1;
int visited[10001];
int s[2];
int result = -1;
int max111 = -1;
void dfs1(int x,int cnt) {
	if (v1[x].size() == 0) {
		if (max111 < cnt) {
			max111 = cnt;
		}
		return;
	}
	for (int i = 0; i < v1[x].size(); i++) {
		int k = v1[x][i];
		dfs1(k, cnt + w1[k]);
	}
}


void dfs(int x,int cnt,int r) {
	
	if (v[x].size() == 0 ) {
		if (max1 <cnt) {
			max1 = cnt;
		}
		return;
	}
	
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		dfs(k, cnt + w[k],r);
		if (s[0] == 0 && x==r) {
			s[0] = max1;
		}
		else if (s[1] == 0 && x == r) {
			s[1] = max1;
		}

		else if (s[0] < max1 && x == r) {
			s[0] = max1;
		}
		sort(s, s + 2);
		result = max(result, s[0] + s[1]);
		if (x == r) {
			max1 = -1;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int a, b, c;
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		w[b] = c;
		sum += c;

		v[a].push_back(b);
		v1[b].push_back(a);
		w1[a] = c;
	}
	
	for (int i = 1; i <= n; i++) {
		max1 = -1;
		max111 = -1;
		if (v[i].size() > 1) {
			dfs1(i, 0);
			s[1] = max111;
			dfs(i, 0,i);
		}
		
		s[0] = 0;
		s[1] = 0;
		for (int j = 1; j <= n; j++) {
			visited[j] = 0;
		}
	}
	if (n == 1) {
		cout << 0 << '\n';
	}
	else if (result == -1) {
		cout << sum << '\n';
	}
	else {
		cout << result << '\n';
	}

}