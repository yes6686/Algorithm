#include <iostream>
#include <queue>
using namespace std;



int main() {
	queue<int>q;
	int n;
	cin >> n;
	string s;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			q.push(x);
		}
		else if (s == "front") {
			if (q.size() >= 1) {
				int k = q.front();
				cout << k << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "back") {
			if (q.size() >= 1) {
				int k = q.back();
				cout << k << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			if (q.empty() == 1) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (s == "pop") {
			if (q.size()>=1) {
				int k = q.front();
				q.pop();
				cout << k << '\n';
			}
			else {
				cout << -1 << '\n';
			}
			
		}
	}
}