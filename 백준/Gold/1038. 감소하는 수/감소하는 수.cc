#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string>v1;
vector<string>v2;
int cnt = 0;

void solve(int n) {
	while (true) {
		if (v2.empty() && v1.empty()) break;
		if (v2.empty()) {
			for (int i = 1;i <= 9;i++) {
				for (int j = 0;j < v1.size();j++) {
					if (to_string(i) <= v1[j]) break;
					v2.push_back(to_string(i) + v1[j]);
					cnt++;
					if (cnt == n) {
						cout << to_string(i) + v1[j] << '\n';
						return;
					}
				}
			}
			v1.clear();
		}
		else {
			for (int i = 1;i <= 9;i++) {
				for (int j = 0;j < v2.size();j++) {
					if (to_string(i) <= v2[j]) break;
					v1.push_back(to_string(i) + v2[j]);
					cnt++;
					if (cnt == n) {
						cout << to_string(i) + v2[j] << '\n';
						return;
					}
				}
			}
			v2.clear();
		}
	}

	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n < 10) {
		cout << n << '\n';
		return 0;
	}

	for (int i = 0;i < 10;i++) {
		v1.push_back(to_string(i));
	}

	cnt = 9;
	solve(n);

}