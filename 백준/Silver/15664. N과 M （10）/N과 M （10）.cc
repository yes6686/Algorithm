#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

int arr[9];
int visited[9];

int n, m;

map<string, int>mp;
vector<string>v;

void bt(int d,string s) {

	for (int i = d; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			bt(i + 1,s+to_string(arr[i])+" ");
			visited[i] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) cnt++;
	}

	if (cnt == m) {
		if (mp[s] == 0) {
			mp[s] = 1;
			v.push_back(s);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	bt(0,"");
	for (int i = 0; i < v.size(); i++) {
		string s = v[i];
		for (int j = 0; j < s.size(); j++) {
			cout << s[j];
		}
		cout << '\n';
	}
}