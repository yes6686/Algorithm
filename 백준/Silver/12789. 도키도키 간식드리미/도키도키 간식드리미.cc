#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int>q;
stack<int>s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	int i = 1;
	while (!q.empty()) {
		int x = q.front();
		if (x == i) {
			i++;
			q.pop();
		}
		else {
			if (!s.empty()) {
				if (s.top() == i) {
					i++;
					s.pop();
				}
				else {
					s.push(x);
					q.pop();
				}
			}
			else {
				s.push(x);
				q.pop();
			}
		}
	}
	while (!s.empty()) {
		int x = s.top();
		s.pop();
		if (x != i) {
			break;
		}
		i++;
	}
	if (s.empty() && q.empty()) {
		cout << "Nice" << '\n';
	}
	else {
		cout << "Sad" << '\n';
	}
}