#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	string s;
	cin >> s;
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	sort(arr , arr + 3);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			cout << arr[0] << ' ';
		}
		else if (s[i] == 'B') {
			cout << arr[1] << ' ';
		}
		else if (s[i] == 'C') {
			cout << arr[2] << ' ';
		}	 
	}
}
