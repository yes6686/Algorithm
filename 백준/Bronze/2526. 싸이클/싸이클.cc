#include <iostream>
using namespace std;


int arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n >> p;

	int s = 1;
	arr[n] = s;
	int k = n;
	int m = n;
	while (true) {
		s++;
		k = m;
		k *= n;
		k %= p;

		if (k == m) {
			cout << 1 << '\n';
			break;
		}

		if (arr[k]) {
			cout << s - arr[k] << '\n';
			break;
		}
		else {
			arr[k] = s;
		}
		m = k;
	}

}