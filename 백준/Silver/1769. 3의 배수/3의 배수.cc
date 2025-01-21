#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int count = 0;
	while (true) {
		if (s.size()==1) {
			if (stoi(s) % 3 == 0) {
				cout << count << '\n';
				cout << "YES" << '\n';
			}
			else {
				cout << count << '\n';
				cout << "NO" << '\n';
			}
			break;
		}
		else {
			int sum = 0;
			for (int i = 0; i < s.size(); i++) {
				sum += s[i] - '0';
			}
			s = to_string(sum);
			count++;
		}
	}
}