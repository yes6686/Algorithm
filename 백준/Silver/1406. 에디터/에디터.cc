#include <iostream>
#include <stack>
using namespace std;

stack<char>st1;
stack<char>st2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		st1.push(s[i]);
	}
	int n;
	cin >> n;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'L') {
			if (st1.size()) {
				char k = st1.top();
				st1.pop();
				st2.push(k);
			}
		}
		else if (c == 'D') {
			if (st2.size()) {
				char k = st2.top();
				st2.pop();
				st1.push(k);
			}
		}
		else if (c == 'B') {
			if(st1.size())
				st1.pop();
		}
		else if (c == 'P') {
			char x;
			cin >> x;
			st1.push(x);
		}
	}
	stack<char>a;
	while (!st1.empty()) {
		a.push(st1.top());
		st1.pop();
	}
	while (!a.empty()) {
		cout << a.top();
		a.pop();
	}
	while (!st2.empty()) {
		cout << st2.top();
		st2.pop();
	}
}