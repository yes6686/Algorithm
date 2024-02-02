#include <iostream>	
using namespace std;

int r[1000001];
int re[1000001];
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		re[arr[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = arr[i] * 2; j <= 1000000; j += arr[i]) {
			if (re[j]) {
				r[j] -= 1;
				r[arr[i]] += 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << r[arr[i]] << ' ';
	}


}