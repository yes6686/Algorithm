#include <iostream>
using namespace std;
int main() {
	int a, b;
	int max = -1;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		sum -= a;
		sum += b;
		if (max < sum) {
			max = sum;
		}
	}
	cout << max;
}