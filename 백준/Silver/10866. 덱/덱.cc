#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int>q;
	string n;
	int T;
	int x;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == "push_back") {
			cin >> x;
			q.push(x);
		}
		else if (n == "push_front") {
			cin >> x;
			q.push(x);
			for (int i = 0; i < q.size() - 1; i++) {
				int k = q.front();
				q.pop();
				q.push(k);
			}
		}
		else if (n == "front") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
			}
		}
		else if (n == "back") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.back() << endl;
			}
		}
		else if (n == "size") {
			cout << q.size() << endl;
		}
		else if (n == "empty") {
			cout << q.empty() << endl;
		}
		else if (n == "pop_front") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (n == "pop_back") {
			if (q.empty()) cout << -1 << endl;
			else {
				for (int i = 0; i < q.size() - 1; i++) {
					int k = q.front();
					q.pop();
					q.push(k);
				}
				cout << q.front() << endl;
				q.pop();
			}
		}

	}

}