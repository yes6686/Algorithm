#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << s[0];
	for (int i = 0; i < (s.size()-2)*2; i++) {
		cout << "e";
	}
	cout << s[s.size() - 1];
}