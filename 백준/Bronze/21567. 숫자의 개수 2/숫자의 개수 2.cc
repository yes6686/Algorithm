#include <iostream>
#include <string>
using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int a, b, c;
	cin >> a >> b >> c;
	long long int res = a * b * c;
	string s = to_string(res);
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
}