#include <iostream>
using namespace std;

string s[3073];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	s[1] = "*";
	s[2] = "* *";
	s[3] = "*****";
	int len = 3;

	int r = 5;
	int t = 6;
	while (len < n) {
		int rr = r;
		for (int i = len+1; i <= len*2; i++) {
			s[i] += s[i-len];
			for (int j = 0; j < rr; j++) {
				s[i] += " ";
			}
			s[i] += s[i - len];
			rr -= 2;
			if (rr == 0) rr = 1;
		}
		len *= 2;
		r +=t;
		t *= 2;
	}
	int kk = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < kk-1; j++) {
			cout << " ";
		}
		cout << s[i]; 
		for (int j = 0; j < kk - 1; j++) {
			cout << " ";
		}
		cout << '\n';
		kk--;
	}
}