#include <iostream>
#include <algorithm>
using namespace std;

string arr[100001];

int diffCnt(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;
	int n;
	string s;
	
	while (T--) {
		cin >> n;
		int sum=100001;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (n >= 48) {
			cout << 0 << '\n';
		}
		else {
			for (int i = 0; i < n-2; i++) {
				for (int j = i + 1; j < n-1; j++) {
					for (int t = j + 1; t < n; t++) {
						sum = min(sum, diffCnt(arr[i], arr[j]) + diffCnt(arr[j], arr[t])
							+ diffCnt(arr[i], arr[t]));
					}
				}
			}
			cout << sum << '\n';
		}
	}
}