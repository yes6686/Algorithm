#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int cnt = 0;

void Z(int x, int y,int s) {
	if (x == r && y == c) {
		cout << cnt << '\n';
		return;
	}
	else if (r>=x && c>=y && r< x+s && c < y+s) {
		Z(x, y, s / 2);
		Z(x, y + s/2, s/2);
		Z(x + s / 2, y, s / 2);
		Z(x + s/2, y + s/2, s/2);
	}
	else {
		cnt+=s*s;
	}
}
int main() {
	cin >> n >> r >> c;
	Z(0, 0, pow(2, n));
}