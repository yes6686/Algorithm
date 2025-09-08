#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	if (a.size() < b.size()) swap(a, b);

	int d = a.size() - b.size();

	for (int i = 0;i < d;i++) {
		cout << a[i];
	}

	for (int i = 0;i < b.size();i++) {
		int s = (a[d + i] - '0') + (b[i] - '0');
		cout << s;
	}
}