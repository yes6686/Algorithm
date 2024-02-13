#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

queue<int>q;

int n, k;
int c[200001];
int minCnt = 100001;

int d[200001];
void bfs(int x) {

	q.push(x);

	while (!q.empty()) {
		int nx = q.front();

		q.pop();

		//cout << "nx : " << nx << '\n';
		if (nx == k) break;
		if (nx > k) {
			if (c[nx - 1] == 0) {
				c[nx - 1] = 1;
				d[nx - 1] = d[nx] + 1;
				q.push(nx - 1);
			}
		}
		else {
			if (abs(k - nx * 2) < abs(k - n)) {
				if (c[nx * 2] == 0) {
					c[nx * 2] = 1;
					d[nx * 2] = d[nx] + 0;
					q.push(nx * 2);
				}
			}
			if (nx - 1 >= 0) {
				if (c[nx - 1] == 0) {
					c[nx - 1] = 1;
					d[nx - 1] = d[nx] + 1;
					q.push(nx - 1);
				}
			}
			if (c[nx + 1] == 0) {
				c[nx + 1] = 1;
				d[nx + 1] = d[nx] + 1;
				q.push(nx + 1);
			}
			
		}
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	bfs(n);
	cout << d[k];
}