#include <iostream>
#include <queue>
#include <stack>
using namespace std;
stack<int>s;
int main() {
	int n;
	cin >> n;
	string a;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push") {
			cin >> k;
			s.push(k);
		}
		else if (a == "top") {
			if (s.empty() == 1) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
		else if (a == "size") {
			cout << s.size() << endl;
		}
		else if (a == "empty") {
			if (s.empty() == 1) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (a == "pop") {
			if (s.empty() == 1) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
	}
}