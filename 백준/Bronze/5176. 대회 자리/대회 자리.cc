#include <iostream>
#include <string.h>
using namespace std;

int visited[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int p, m;
		cin >> p >> m;
		int ans = 0;
		for (int i = 0; i < p; i++) {
			int x;
			cin >> x;
			if (visited[x] == 0) {
				visited[x] = 1;
				ans++;
			}
		}
		cout << p-ans << '\n';
		memset(visited, 0, sizeof(visited));
	}
}