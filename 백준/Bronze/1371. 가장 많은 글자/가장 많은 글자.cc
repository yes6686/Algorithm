#include <iostream>
using namespace std;

int arr[27];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int maxCnt = 0;
	while (cin >> s) {
		for (int i = 0; i < s.size(); i++) {
			arr[s[i]-97]++;
			maxCnt = max(maxCnt, arr[s[i] - 97]);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (maxCnt == arr[i]) {
			cout << (char)(i + 'a');
		}
	}
}