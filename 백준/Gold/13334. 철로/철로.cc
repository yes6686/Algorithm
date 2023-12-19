#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct pqcmp {
	bool operator()(pair<int, int>x, pair<int, int>y) {
		if (x.first == y.first) {
			return x.second > y.second;
		}
		else {
			return x.first > y.first;
		}
	}
};

bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.second == y.second) {
		return x.first < y.first;
	}
	else {
		return x.second < y.second;
	}
}

vector<pair<int, int>>v;
priority_queue<pair<int, int >,vector<pair<int,int>>,pqcmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int h, o;
	for (int i = 0; i < n; i++) {
		cin >> h >> o;
		if (h > o) {
			v.push_back({ o,h });
		}
		else {
			v.push_back({ h,o });
		}
	}
	sort(v.begin(), v.end(), cmp);
	int d;
	cin >> d;
	int ans=0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int s = v[i].first;
		int e = v[i].second;
		if (e - s > d) continue;
		pq.push({ s,e });
		while (!pq.empty()) {
			if (pq.top().first + d < e) {
				pq.pop();
			}
			else {
				ans = max(ans, int(pq.size()));
				break;
			}
		}
	}
	cout << ans;
}