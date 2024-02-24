#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int arr[51];
map<string, int>mp;
queue<string>q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string samplePolygon = "";
	for (int i = 0; i < n; i++) {  // 1: 오른 , 2: 위 , 3: 왼 , 4: 아래
		char x;
		cin >> x;
		samplePolygon += x;
	}
	mp[samplePolygon] = 1;
	string rSamplePolygon = samplePolygon;
	reverse(rSamplePolygon.begin(), rSamplePolygon.end());
	for (int i = 0; i < rSamplePolygon.size(); i++) {
		if (rSamplePolygon[i] == '1') {
			rSamplePolygon[i] = '3';
		}
		else if (rSamplePolygon[i] == '2') {
			rSamplePolygon[i] = '4';
		}
		else if (rSamplePolygon[i] == '3') {
			rSamplePolygon[i] = '1';
		}
		else {
			rSamplePolygon[i] = '2';
		}
	}
	mp[rSamplePolygon] = 1;
	for (int i = 0; i < n - 1; i++) {
		string s = "";
		for (int j = 1; j < samplePolygon.size(); j++) {
			s += samplePolygon[j];
		}
		s += samplePolygon[0];
		mp[s] = 1;
		samplePolygon = s;
	}

	for (int i = 0; i < n - 1; i++) {
		string s = "";
		for (int j = 1; j < rSamplePolygon.size(); j++) {
			s += rSamplePolygon[j];
		}
		s += rSamplePolygon[0];
		mp[s] = 1;
		rSamplePolygon = s;
	}
	int m;
	cin >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string k = "";
		for (int j = 0; j < n; j++) {
			char x;
			cin >> x;
			k += x;
		}
		if (mp[k] == 1) {
			cnt++;
			q.push(k);
		}
	}
	cout << cnt << '\n';
	while (!q.empty()) {
		string h = q.front();
		q.pop();
		for (int i = 0; i < h.size(); i++) {
			cout << h[i] << ' ';
		}
		cout << '\n';
	}
}