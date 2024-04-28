#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
		
	int n;
	cin >> n;
	int p, t;
	cin >> p >> t;

	int h = 1;
	int s = 0;
	t--;
	int check = 0;
	while (t--) {
		s += h;
		if(s>n*2)
			s %= n*2;
		if (s == 4 * n) {
			s = n * 2;
		}
		if (check == 0) {
			h++;
		}
		else {
			h--;
		}
		if (h == 2 * n) {
			check = 1;
		}
		if (h == 1) {
			check = 0;
		}
	}
	int c = 0;
	for (int i = s+1; i <= s + h; i++) {
		int g = i;
		if (g > 2 * n) {
			g %= 2 * n;
		}
		if (g == 4 * n) {
			g = 2 * n;
		}
		if (p * 2 - 1 == g || p * 2 == g) {
			c = 1;
			break;
		}
	}
	if (c == 1) {
		cout << "Dehet YeonJwaJe ^~^";
	}
	else {
		cout << "Hing...NoJam";
	}
}