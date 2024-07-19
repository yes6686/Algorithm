#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, l;
	cin >> n >> k >> l;
	int cnt = 0;
	string s = "";
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a >= l && b >= l && c >= l) && (a + b + c >= k)) {
			cnt++;
			s += to_string(a);
			s += " ";
			s += to_string(b);
			s += " ";
			s += to_string(c);
			s += " ";
		}
	}
	cout << cnt<<'\n';
	cout << s;
}