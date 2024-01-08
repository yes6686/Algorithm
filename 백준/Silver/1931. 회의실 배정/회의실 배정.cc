#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x, y;
	while (n--) {
		cin >> x >> y;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());
	int s = v[0].first;
	int cnt = 1;
	for (int i = 1; i < v.size(); i++) {
		if (s <= v[i].second) {
			s = v[i].first;
			cnt++;
		}
	}
	cout << cnt;


}