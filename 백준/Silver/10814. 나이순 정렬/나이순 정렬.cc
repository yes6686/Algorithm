#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, string>>v;

bool compare(pair<int, string>a, pair<int, string>b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;
	int a;
	string b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		//cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout<< v[i].first <<' ' << v[i].second<<'\n';
	}

}