#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int tail[101][101];

char w[10001];

int n;
int ex = 0;
queue<pair<int, int>>q;
// 오른쪽 : 1 왼쪽 : 2 아래 : 3 위쪽 : 4 
void go(int x, int y, int d,int cnt) { 
	if (ex) return;
	if (x <= 0 || y <= 0 || x > n || y > n) {
		cout << cnt-1;
		ex++;
		return;
	}
	if (d == 1) {
		if (tail[x][y + 1] == 2) {
			cout << cnt;
			ex++;
			return;
		}
		tail[x][y + 1] = 2;
		q.push(make_pair(x, y + 1));
		if (arr[x][y + 1] == 0) {
			tail[q.front().first][q.front().second] = 0;
			q.pop();
		}
		arr[x][y + 1] = 0;
		if (w[cnt] == 'L') {
			go(x, y + 1, 4, cnt + 1);
		}
		else if (w[cnt] == 'D') {
			go(x, y + 1, 3, cnt + 1);
		}
		else {
			go(x, y + 1, 1, cnt + 1);
		}
	}
	else if (d == 2) {
		if (tail[x][y - 1] == 2 ) {
			cout << cnt;
			ex++;
			return;
		}
		tail[x][y - 1] = 2;
		q.push(make_pair(x, y - 1));
		if (arr[x][y - 1] == 0) {
			tail[q.front().first][q.front().second] = 0;
			q.pop();
		}
		arr[x][y - 1] = 0;
		if (w[cnt] == 'L') {
			go(x, y - 1, 3, cnt + 1);
		}
		else if (w[cnt] == 'D') {
			go(x, y - 1, 4, cnt + 1);
		}
		else {
			go(x, y - 1, 2, cnt + 1);
		}
	}
	else if (d == 3) {
		if (tail[x+1][y] == 2 ) {
			cout << cnt;
			ex++;
			return;
		}
		tail[x + 1][y] = 2;
		q.push(make_pair(x + 1, y));
		if (arr[x + 1][y] == 0) {

			tail[q.front().first][q.front().second] = 0;
			q.pop();

		}
		arr[x + 1][y] = 0;
		if (w[cnt] == 'L') {
			go(x + 1, y, 1, cnt + 1);
		}
		else if (w[cnt] == 'D') {
			go(x + 1, y, 2, cnt + 1);
		}
		else {
			go(x + 1, y, 3, cnt + 1);
		}
	}
	else if (d == 4) {
		if (tail[x - 1][y] == 2 ) {
			cout << cnt;
			ex++;
			return;
		}
		tail[x - 1][y] = 2;
		q.push(make_pair(x - 1, y));
		if (arr[x - 1][y] == 0) {
			tail[q.front().first][q.front().second] = 0;
			q.pop();	
		}
		arr[x + 1][y] = 0;
		if (w[cnt] == 'L') {
			go(x - 1, y, 2, cnt + 1);
		}
		else if (w[cnt] == 'D') {
			go(x - 1, y, 1, cnt + 1);
		}
		else {
			go(x - 1, y, 4, cnt + 1);
		}
	}
}

int main() {

	
	cin >> n;
	int k;
	cin >> k;
	int x, y;
	tail[1][1] = 2;
	q.push(make_pair(1, 1));

	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
	}
	int L;
	cin >> L;
	int X;
	char c;
	for (int i = 0; i < L; i++) {
		cin >> X >> c;
		w[X] = c;
	}
	go(1, 1, 1, 1);
	


}