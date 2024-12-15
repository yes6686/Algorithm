#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s1, s2;
	cin >> s1 >> s2;

	if (n % 2 == 0) {
		if (s1 == s2) {
			cout << "Deletion succeeded" << '\n';
		}
		else {
			cout << "Deletion failed" << '\n';
		}
	}
	else {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == s2[i]) {
				cout << "Deletion failed" << '\n';
				return 0;
			}
		}
		cout << "Deletion succeeded" << '\n';
	}

}