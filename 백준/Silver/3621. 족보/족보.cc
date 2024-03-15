#include <iostream>
using namespace std;

int de[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		de[x]++;
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (de[i] > d) {
			int k = 0;
			while (de[i] >= d) {
				k++;
				de[i] -= d;
			}
			ans += k;
			if (de[i] > 0) {
				k++;
			}
			de[i] = k;
			i--;
		}
	}
	cout << ans;
}