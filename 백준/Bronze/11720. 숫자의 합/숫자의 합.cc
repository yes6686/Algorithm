#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (s[i]-'0');
	}
	cout << sum;
}