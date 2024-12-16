#include <iostream>
using namespace std;

int visited[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (visited[x] == 1) {
			cnt++;
		}
		else {
			visited[x] = 1;
		}
	}
	cout << cnt << '\n';
}