#include <iostream>
#include <queue>
using namespace std;
queue<int>q;
void DFS(long long int a, long long int b,long long int cnt) {
	if (a > b) {
		return;
	}
	if (a == b) {
		q.push(cnt);
		return;
	}
	DFS(a * 2, b, cnt + 1);
	DFS(a * 10+1, b, cnt + 1);
}

int main() {
	long long int a, b;
	cin >> a >> b;
	DFS(a, b,1);
	long long int min = 90000000000;
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		if (min > k) {
			min = k;
		}
		//cout << k << endl;
	}
	if (min == 90000000000) {
		cout << -1 << endl;
	}else
	cout << min << endl;

}