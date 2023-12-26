#include <iostream>
using namespace std;

int arr[201][201];

void go(int x, int y, int d, int g) { // 0 : 우 1 : 상 2: 좌  3 :하

	int a = x;
	int b = y;
	arr[a][b] = 1;
	if (d == 0) {

		int k = g+1;
		string s="";
		while (k--) {
			if (s == "") {
				s += "0";
				b += 1;
				arr[a][b] = 1;
			}
			else {
				for (int i = s.size()-1; i >=0; i--) {
					if (s[i] == '0') {
						a -= 1;
						arr[a][b] = 1;
						s += "1";
					}
					else if (s[i] == '1') {
						b -= 1;
						arr[a][b] = 1;
						s += "2";
					}
					else if (s[i] == '2') {
						a += 1;
						arr[a][b] = 1;
						s += "3";
					}
					else if (s[i] == '3') {
						b += 1;
						arr[a][b] = 1;
						s += "0";
					}
				}
			}
		}


	}
	else if (d == 1) {

		int k = g + 1;
		string s = "";
		while (k--) {
			if (s == "") {
				s += "1";
				a -= 1;
				arr[a][b] = 1;
			}
			else {
				for (int i = s.size() - 1; i >= 0; i--) {
					if (s[i] == '0') {
						a -= 1;
						arr[a][b] = 1;
						s += "1";
					}
					else if (s[i] == '1') {
						b -= 1;
						arr[a][b] = 1;
						s += "2";
					}
					else if (s[i] == '2') {
						a += 1;
						arr[a][b] = 1;
						s += "3";
					}
					else if (s[i] == '3') {
						b += 1;
						arr[a][b] = 1;
						s += "0";
					}
				}
			}
		}
	}
	else if (d == 2) {
		int k = g + 1;
		string s = "";
		while (k--) {
			if (s == "") {
				s += "2";
				b -= 1;
				arr[a][b] = 1;
			}
			else {
				for (int i = s.size() - 1; i >= 0; i--) {
					if (s[i] == '0') {
						a -= 1;
						arr[a][b] = 1;
						s += "1";
					}
					else if (s[i] == '1') {
						b -= 1;
						arr[a][b] = 1;
						s += "2";
					}
					else if (s[i] == '2') {
						a += 1;
						arr[a][b] = 1;
						s += "3";
					}
					else if (s[i] == '3') {
						b += 1;
						arr[a][b] = 1;
						s += "0";
					}
				}
			}
		}
	}
	else if (d == 3) {
		int k = g + 1;
		string s = "";
		while (k--) {
			if (s == "") {
				s += "3";
				a += 1;
				arr[a][b] = 1;
			}
			else {
				for (int i = s.size() - 1; i >= 0; i--) {
					if (s[i] == '0') {
						a -= 1;
						arr[a][b] = 1;
						s += "1";
					}
					else if (s[i] == '1') {
						b -= 1;
						arr[a][b] = 1;
						s += "2";
					}
					else if (s[i] == '2') {
						a += 1;
						arr[a][b] = 1;
						s += "3";
					}
					else if (s[i] == '3') {
						b += 1;
						arr[a][b] = 1;
						s += "0";
					}
				}
			}
		}
	}



}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int x, y, d, g;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		go(y+100, x+100, d, g);

	}
	int cnt = 0;
	for (int i = 0; i <= 199; i++) {
		for (int j = 1; j <= 200; j++) {
			if (arr[i][j - 1] && arr[i][j]) {
				if (arr[i + 1][j - 1] && arr[i + 1][j]) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
}
