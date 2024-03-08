// 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minArr[500001];
int maxArr[500001];

int SminArr[500001];
int SmaxArr[500001];

vector<int>smax;
vector<int>smin;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		smax.push_back(a + b);
		smin.push_back(a - b);
		minArr[i] = a - b;
		maxArr[i] = a + b;
	}

	sort(smax.begin(), smax.end());
	sort(smin.begin(), smin.end());

	for (int i = 0; i < n; i++) {
		int kf =lower_bound(smax.begin(), smax.end(), minArr[i])-smax.begin() + 1;
		int ks = upper_bound(smin.begin(), smin.end(), maxArr[i]) - smin.begin();
		cout << kf << " " << ks << '\n';
	}

}