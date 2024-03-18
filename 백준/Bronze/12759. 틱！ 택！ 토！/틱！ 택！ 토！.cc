#include <iostream>
using namespace std;

int arr[4][4];
int s[9];

int main() {
	int n;
	cin >> n;
	int ss = (n == 1) ? 2 : 1;
	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			s[i] = n;
		}
		else {
			s[i] = ss;
		}
	}
	int ansC = 0;
	for (int i = 0; i < 9; i++) {
		int a, b;
		cin >> a >> b;
		if (ansC == 1) {
			continue;
		}
		arr[a][b] = s[i];
		int check = 1;
		for (int j = 1; j <= 3; j++) {
			if (arr[a][j] != s[i]) {
				check = 0;
			}
		}
		if (check == 1) {
			ansC = 1;
			cout << s[i] << '\n';
			continue;
		}
		else {
			check = 1;
		}
		for (int j = 1; j <= 3; j++) {
			if (arr[j][b] != s[i]) {
				check = 0;
			}
		}
		if (check == 1) {
			ansC = 1;

			cout << s[i] << '\n';
			continue;
		}
		else {
			check = 1;
		}
		for (int j = 1; j <= 3; j++) {
			if (arr[j][j] != s[i]) {
				check = 0;
			}
		}
		if (check == 1) {
			ansC = 1;
			cout << s[i] << '\n';
			continue;
		}
		else {
			check = 1;
		}
		for (int j = 1; j <= 3; j++) {
			if (arr[j][4-j] != s[i]) {
				check = 0;
			}
		}
		if (check == 1) {
			ansC = 1;
			cout << s[i] << '\n';
			continue;
		}
		else {
			check = 1;
		}
	}
	if (ansC == 0) {
		cout << 0<<'\n';
	}
}