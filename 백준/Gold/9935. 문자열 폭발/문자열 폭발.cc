#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<char>stk;
stack<char>stk1;
stack<char>ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string b;
	cin >> b;
	string st = "";
	for (int i = 0; i < s.size(); i++) {
		st += s[i];
		stk.push(s[i]);
		if (st.size() != b.size())continue;
		if (st == b ) {
			for (int j = 0; j < b.size(); j++) {
				stk.pop();
			}
			st = "";
			for (int j = 0; j < b.size() - 1; j++) {
				if (stk.size() == 0) break;
				char k = stk.top();
				stk.pop();
				stk1.push(k);
			}
			while (!stk1.empty()) {
				stk.push(stk1.top());
				st += stk1.top();
				stk1.pop();
			}
		}
		else {
			string ccc = "";
			for (int j = 1; j < st.size(); j++) {
				ccc += st[j];
			}
			st = ccc;
		}
	}
	if (stk.size() == 0) {
		cout << "FRULA";
		return 0;
	}
	while (!stk.empty()) {
		ans.push(stk.top());
		stk.pop();
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}