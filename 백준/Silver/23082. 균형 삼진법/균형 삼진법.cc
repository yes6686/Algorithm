#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

string s = "";

stack<string>st;

void dfs(int n) {

	if (n == 0) return;

	dfs(n / 3);
	s += to_string(n % 3);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	dfs(abs(n));


	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '2') {
			if (i == 0) {
				st.push("T");
				st.push("1");
			}
			else {
				if (s[i - 1] == '1') {
					s[i - 1] = '2';
				}
				else if (s[i - 1] == '2') {
					s[i - 1] = '3';
				}
				else {
					s[i - 1] = '1';
				}
				st.push("T");
			}
		}
		else if (s[i] == '3') {
			if (i == 0) {
				st.push("0");
				st.push("1");
			}
			else {
				if (s[i - 1] == '1') {
					s[i - 1] = '2';
				}
				else if (s[i - 1] == '2') {
					s[i - 1] = '3';
				}
				else {
					s[i - 1] = '1';
				}
				st.push("0");
			}
		}
		else if (s[i] == '1') {
			st.push("1");
		}
		else {
			st.push("0");
		}
	}
	while (!st.empty()) {
		if (n < 0) {
			if (st.top() == "T") {
				cout << "1";
			}
			else if (st.top() == "1") {
				cout << "T";
			}
			else {
				cout << "0";
			}
		}
		else {
			cout << st.top();
		}
		st.pop();
	}
}