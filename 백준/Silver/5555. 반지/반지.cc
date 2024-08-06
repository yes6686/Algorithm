#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string f;
	cin >> f;
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		str += str;
		for (int t = 0; t < 10; t++) {
			string s = "";
			for (int j = 0; j < f.size(); j++) {
				s += str[t + j];
			}
			if (s == f) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt << '\n';
}