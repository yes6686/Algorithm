#include <iostream>
#include <string.h>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int v, s;
		cin >> v;
		int ans = 1001;
		int maxCnt = 0;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < v; i++) {
			cin >> s;
			arr[s]++;
			if (maxCnt <= arr[s]) {
				if (maxCnt == arr[s]) {
					if (ans > s) {
						ans = s;
					}
				}
				else {
					ans = s;
				}
				maxCnt = arr[s];
			}
		}
		cout << ans << '\n';
	}

}