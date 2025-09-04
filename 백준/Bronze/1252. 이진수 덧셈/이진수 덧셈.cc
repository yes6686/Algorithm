#include <iostream>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	if (a.size() < b.size()) {
		swap(a, b);
	}

	while (a.size() != b.size()) {
		b = '0' + b;
	}
	
	string temp = "";
	int flag = 0;

	for (int i = a.size() - 1; i >= 0;i--) {

		int t1 = (a[i] == '1') ? 1 : 0;
		int t2 = (b[i] == '1') ? 1 : 0;

		if (t1 + t2 + flag == 3) {
			temp = '1' + temp;
		}
		else if (t1 + t2 + flag == 2) {
			flag = 1;
			temp = '0' + temp;
		}
		else if (t1 + t2 + flag == 1) {
			flag = 0;
			temp = '1' + temp;
		}
		else {
			temp = '0' + temp;
		}
	}

	if (flag == 1) temp = '1' + temp;

	string ans = "";
	flag = 0;
	for (int i = 0;i < temp.size();i++) {
		if (temp[i] != '0') flag = 1;
		if (flag == 1) {
			ans += temp[i];
		}
	}
	if (flag == 1) cout << ans << '\n';
	else cout << 0;
}
