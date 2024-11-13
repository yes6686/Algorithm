#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;

	while (cin >> n >> m) {
		int cnt = 0;
		for (int i = n; i <= m; i++) {
			string s = to_string(i);
			int check = 1;
			memset(arr, 0, sizeof(arr));
			for (int j = 0; j < s.size(); j++) {
				arr[s[j] - '0']++;
				if (arr[s[j] - '0'] > 1) {
					check = 0;
					break;
				}
			}
			if (check == 1) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}