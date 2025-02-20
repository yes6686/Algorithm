#include <iostream>
#include <algorithm>
using namespace std;

string arr[1001];

bool compare(string a, string b) {
	return a+b > b+a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n,compare);
	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += arr[i];
	}
	while (true) {
		if (ans[0] == '0') {
			ans = ans.substr(1);
		}
		else {
			break;
		}
	}
	if (ans == "") {
		cout << 0 << '\n';
	}
	else {
		cout << ans << '\n';
	}
}