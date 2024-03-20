#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a[100001];
int b[100001];
int x[100001];
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	int check = 1;
	int maxC = 0;
	for (int i = 0; i < n; i++) {
		int k = abs(a[i] - b[i]);
		if (k % x[i] != 0) {
			check = 0;
			break;
		}
		v.push_back(k / x[i]);
		maxC = max(maxC, k / x[i]);
	}
	int isAllh = 1; // 모두 홀수
	int isAllw = 1; // 모두 짝수
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			isAllh = 0;
		}
		else {
			isAllw = 0;
		}
	}
	if (check == 0 || (isAllh==0 && isAllw==0)) {
		cout << -1;
	}
	else {
		cout << maxC;
	}
}
