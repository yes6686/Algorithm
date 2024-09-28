#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int maxS = -1, minE=100001;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		maxS = max(maxS, s);
		minE = min(minE, e);
	}
	if (maxS - minE < 0) {
		cout << 0;
	}
	else {
		cout << maxS - minE;
	}
}