#include <iostream>
#include <string.h>
using namespace std;

int arr[1423];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		for(int i=0;i<n;i++){ 
			int x;
			cin >> x;
			arr[x] = 1;
		}
		int e = 0;
		int check = 1;
		for (int i = 0; i < 1422; i++) {
			if (arr[i] == 1) {
				e = 200;
			}
			else {
				e--;
				if (e < 0) {
					check = 0;
					break;
				}
			}
		}
		for (int i = 1422; i >= 0; i--) {
			if (arr[i] == 1) {
				e = 200;
			}
			else {
				e--;
				if (e < 0) {
					check = 0;
					break;
				}
			}
		}
		if (check == 1) {
			cout << "POSSIBLE" << '\n';
		}
		else {
			cout << "IMPOSSIBLE" << '\n';
		}
		memset(arr, 0, sizeof(arr));
	}
}