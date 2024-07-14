#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int A, B, C;
	cin >> A >> B >> C;
	int n;
	cin >> n;
	int maxAns = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			sum += A * a + B * b + C * c;
		}
		maxAns = max(maxAns, sum);
	}
	cout << maxAns;
}