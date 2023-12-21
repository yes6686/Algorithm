#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std; 
bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {

	int T;
	string n[20001];
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> n[i];
	}
	sort(n, n + T,compare);
	cout << n[0] << endl;
	for (int i = 1; i < T; i++) {
		if (n[i] != n[i - 1]) {
		cout << n[i] << '\n';
		}
	}
}