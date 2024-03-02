#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

pair<int, int> arr[101];
int ch[101];
int c[101];
int dis[101];
int n, m;
int a, b; // 출발층, 도착층
int ss[100001];
queue<pair<int,int>>q;
stack<int>s;

int IsCheck(int x, int i) { //i번째 엘리베이터에 x가 있는지 확인
	if ((x - (arr[i].first - arr[i].second)) % arr[i].second == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int IsConnect(int i, int j) {
	memset(ss, 0, sizeof(ss));
	int k1 = arr[i].first;
	while (k1 <= n) {
		ss[k1] = 1;
		k1 += arr[i].second;
	}
	int k2 = arr[j].first;
	while (k2 <= n) {
		if (ss[k2] == 1) return 1;
		k2 += arr[j].second;
	}

	return 0;
}

void bfs(int M, int cnt) {
	q.push({ M,cnt });
	c[M] = 1;
	dis[M] = M;
	while (!q.empty()) {
		int km = q.front().first;
		int kc = q.front().second;
		q.pop();
		if (IsCheck(b, km) == 1) continue;

		for (int i = 1; i <= m; i++) {
			if (km!=i && IsConnect(km,i)==1 && c[i] > kc + 1) {
				c[i] = kc + 1;
				dis[i] = km;
				q.push({ i,kc + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i < 101; i++) {
		c[i] = 101;
	}
	cin >> n >> m;
	int mini = 100001;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i].first >> arr[i].second;
		mini = min(mini, arr[i].first);
	}
	cin >> a >> b;
	if (mini > a || mini > b) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		if (IsCheck(b, i) == 1) {
			ch[i] = 1;
		}
	}

	for (int i = 1; i <= m; i++) {
		if (IsCheck(a, i) == 1) {
			bfs(i, 1);
		}
	}
	int minAns = 101;
	int index;
	for (int i = 1; i <= m; i++) {
		if (IsCheck(b, i) == 1) {
			if (c[i] != 101) {
				if (minAns > c[i]) {
					minAns = c[i];
					index = i;
				}
			}
		}
	}
	if (minAns == 101) {
		cout << -1;
	}
	else {
		cout << c[index] << '\n';
		while (1) {
			s.push(index);
			if (index == dis[index]) break;
			index = dis[index];

		}
		while (!s.empty()) {
			cout << s.top() << '\n';
			s.pop();
		}
	}
}