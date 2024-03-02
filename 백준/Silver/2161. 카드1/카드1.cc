#include <iostream>
#include <queue>
using namespace std;
queue<int>q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		cout << k << ' ';
		if (q.size() ==1) {
			cout << q.front();
			break;
		}
		else {
			if (q.size() > 0) {
				k = q.front();
				q.pop();
				q.push(k);
			}
		}

	}
	


}