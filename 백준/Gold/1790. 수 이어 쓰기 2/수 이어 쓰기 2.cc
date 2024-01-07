#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n, k;
	cin >> n >> k;
	if (n < 10) {
		if (n >= k) {
			cout << k << '\n';
		}
		else {
			cout << -1 << '\n';
		}
		return 0;
	}
	if (k < 10) {
		if (n >= k) {
			cout << k << '\n';
		}
		else {
			cout << -1 << '\n';
		}
		return 0;
	}
	string v = "9";
	long long int s = 1;
	long long int totalLength = 0;
	string vv = "9";
	long long int kk = n;
	while (1) {
		if (n > stoi(v)) {
			totalLength += s * (stoi(vv));
			s += 1;
			vv += "0";
			v += "9";
		}
		else {
			string nk = "";
			for (int i = 0; i < v.size() - 1; i++) {
				nk += v[i];
			}
			kk -= (stoi(nk));
			totalLength += (kk * s);
			break;
		}
	}
	if (totalLength < k) {
		cout << -1 << '\n';
		return 0;
	}

	s = 1;
	v = "9";
	vv = "9";
	long long int a = 0;
	kk = k;
	while (1) {
		if (k > a + s * (stoi(vv))) {
			a += s * (stoi(vv));
			s += 1;
			vv += "0";
			v += "9";
		}
		else {
			k -= a;
			long long int l = k % s;
			long long int h = k / s;

			string nk = "";
			for (int i = 0; i < v.size() - 1; i++) {
				nk += v[i];
			}
			if (l == 0) {
				string aa = to_string(stoi(nk) + h);
				cout << aa.back();
			}
			else {
				string aa = to_string(stoi(nk) + h + 1);
				cout << aa[l - 1];
			}
			break;
		}
	}
}