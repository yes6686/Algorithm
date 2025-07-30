#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;
	
	int i = 0;
	int s = 1;
	while (true) {
		if (i >= n) break;
		string str = to_string(s);

		if (str.find(to_string(l)) == string::npos) {
			i++;
			s++;
		}
		else {
			s++;
		}
	}
	cout << s-1 << '\n';
}