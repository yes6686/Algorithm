#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>v0;
vector<int>v1;

int main() {
	int n, m;
	cin >> n >> m;
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0) { // 가로로 자르는 점선
			v0.push_back(b);
		}
		else { // 세로로 자르는 점선
			v1.push_back(b);
		}
	}
	v0.push_back(0);
	v0.push_back(m);
	v1.push_back(0);
	v1.push_back(n);
	sort(v0.begin(), v0.end());
	sort(v1.begin(), v1.end());

	int maxAns = 1;
	
	for (int i = 1; i < v0.size(); i++) {
		int h = v0[i]-v0[i-1];
		for (int j = 1; j < v1.size(); j++) {
			int w = v1[j] - v1[j - 1];
			maxAns = max(maxAns, h * w);
		}
	}
	cout << maxAns;
}