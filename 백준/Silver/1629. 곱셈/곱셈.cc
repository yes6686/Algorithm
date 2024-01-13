#include <iostream>

using namespace std;
long long int recur(long long int x, long long int y, long long int z, long long int w) {
	if (y == 1) {
		return  (x * w) % z;
	}

	if (y % 2 == 1) {
		w *= x;
		w %= z;
		y -= 1;
	}
	long long int r = (x * x) % z;

	return recur(r, y / 2, z, w);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int result;
	int a, b, c;

	cin >> a >> b >> c;
	result = recur(a, b, c, 1);
	cout << result;



}