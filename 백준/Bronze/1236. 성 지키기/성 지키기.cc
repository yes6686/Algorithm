#include <iostream>
using namespace std;

int arr[51][51];
int r[51];
int c[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			if (s[j] == 'X') {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == 1) {
				r[i] = 1;
				c[j] = 1;
			}
		}
	}

	int rcnt = 0;
	int ccnt = 0;
	

	for (int i = 0;i < n;i++) {
		if (r[i] == 0) rcnt++;
	}

	for (int i = 0;i < m;i++) {
		if (c[i] == 0) ccnt++;
	}

	int ans = (rcnt < ccnt) ? ccnt : rcnt;
	cout << ans << '\n';
}