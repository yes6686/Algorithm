#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>>v;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i].first<<' ' << v[i].second << '\n';
	}
	
}