#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector<pair<int, string>> rooms[301]; // queue 대신 vector 사용

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int p, m;
	cin >> p >> m;
	for (int i = 0; i < p; i++) {
		int l;
		string s;
		cin >> l >> s;
		for (int j = 0; j < p; j++) {
			if (rooms[j].size() >= m) continue;
			if (rooms[j].empty()) {
				rooms[j].push_back({ l,s });
				break;
			}
			if (abs(rooms[j].front().first - l) > 10) continue;
			rooms[j].push_back({l,s});
			break;
		}
	}

	for (int i = 0; i < p; i++) {
		if (rooms[i].size() == 0) break;
		if (rooms[i].size() == m) {
			cout << "Started!" << '\n';
		}
		else {
			cout << "Waiting!" << '\n';
		}
		sort(rooms[i].begin(), rooms[i].end(), compare);
		for (int j = 0; j < rooms[i].size(); j++) {
			cout << rooms[i][j].first << " " << rooms[i][j].second << '\n';
		}
	}
}