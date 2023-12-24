#include <iostream>
#include <queue>
using namespace std;

queue<int>q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		int x;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			q.push(x);
		}
		for (int i = 0; i < m; i++) {
			cin >> x;
			while (!q.empty()) {
				if (q.front() == x) {
					cnt++;
					q.pop();
					break;
				}
				else if(q.front()<x){
					q.pop();
				}
				else {
					break;
				}
			}		
		}
		cout << cnt << '\n';
	}
}
