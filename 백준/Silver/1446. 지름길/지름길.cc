#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001];
vector<pair<int,pair<int, int>>>v;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) {
	if (a.first == b.first) {
		return a.second.first > b.second.first;
	}
	else {
		return a.first > b.first;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	int a, b, c;
	for (int i = 0; i <= d; i++) {
		dp[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,{ b,c } });
	}
	sort(v.begin(), v.end(), compare);
	while(!v.empty()) {
		a = v.back().first;
		b = v.back().second.first;
		c = v.back().second.second;
		v.pop_back();
		if (b > d) continue;
		if (b - a <= c) continue;
		dp[b] = min(dp[b], dp[a] + c);
		for (int j = 1; j <= d; j++) {
			dp[j] = min(dp[j], dp[j - 1] + 1);
		}
	}
	cout << dp[d];
}