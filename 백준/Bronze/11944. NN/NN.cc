#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string n;
	int m;
	cin >> n >> m;
	if (n.size() * stoi(n) > m) {
		int a = m / n.size();
		int b = m % n.size();
		for (int i = 0; i < a; i++) {
			cout << n;
		}
		for (int i = 0; i < b; i++) {
			cout << n[i];
		}
	}
	else {
		for (int i = 0; i < stoi(n); i++) {
			cout << n;
		}
	}
}